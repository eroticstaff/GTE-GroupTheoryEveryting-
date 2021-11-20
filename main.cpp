#include <iostream>
#include <vector>
#include <string>

#include "LinearAlgebra.h"
#include "GroupTheory.h"
#include "AlgebraUtils.h"

using namespace std;

int main() {
    int command;
    int n;
    cout << "Enter 1 for GL(2,Z), 2 for S(n)" << endl;
    cin >> command;
    if (command == 1) {
        vector<MatrixGroupElement> groupElements;
        Matrix e(2);
        cout << "Enter e element:" << endl;
        e.input();
        MatrixGroupElement E("E", e);
        cout << "Enter number of elements:" << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string name;
            cout << "Enter name of element>>";
            cin >> name;
            Matrix m(2);
            cout << "Enter matrix:" << endl;
            m.input();
            MatrixGroupElement M(name, m);
            groupElements.push_back(M);
        }
        Group<MatrixGroupElement> GL2(groupElements, E);
        cout << "You entered:" << endl;
        GL2.printElements();
        cout << "Generating group..." << endl;
        GL2.getElementsOrder();
        GL2.generateGroup();
        cout << "Finding group center..." << endl;
        GL2.findCenter();
    } else {
        vector<SubstitutionGroupElement> groupElements;
        vector<string> e_str = {""};
        Substitution e(e_str);
        cout << "Enter number of substitutions:" << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            vector<string> independent_cycles;
            int m;
            string name;
            cout << "Enter name of the element:" << endl;
            cin >> name;
            cout << "Enter number of independent cycles of " << i << " substitution:" << endl;
            cin >> m;
            for (int j = 0; j < m; j++) {
                string subs;
                cout << "Enter " << m << " independent cycle (without brackets):" << endl;
                cin >> subs;
                independent_cycles.push_back(subs);
            }
            Substitution newSubstination(independent_cycles);
            groupElements.push_back(SubstitutionGroupElement(name, newSubstination));
        }
        SubstitutionGroupElement E("E", e);
        E.print();
        Group<SubstitutionGroupElement> SN(groupElements, E);
        SN.printElements();
        SN.getElementsOrder();
        SN.generateGroup();
        cout << "Group center:" << endl;
        SN.findCenter();
    }
    return 0;
}
