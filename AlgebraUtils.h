//
// Created by xyamix on 19.11.2021.
//

#ifndef GROUPTHEORY_ALGEBRAUTILS_H
#define GROUPTHEORY_ALGEBRAUTILS_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Substitution {
private:
    vector<string> substitution;
public:
    Substitution();
    Substitution(vector<string> substitution);

    Substitution& operator=(const Substitution &A);
    Substitution operator*(Substitution &A);
    bool operator==(Substitution &A);

    vector<string> get_substitution() const;
    void delete_empty();
    void input();
    void print();
    bool isEqual(string s1, string s2);
    int find_not_used(vector<int> used);
    int get_next(int k);
    int get_next_in_subs(int k, const string subs);
    int get_element_index(int k, const string subs);
};


#endif //GROUPTHEORY_ALGEBRAUTILS_H
