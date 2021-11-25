#ifndef GROUPTHEORYUTILS_GROUPTHEORYUTILS_H
#define GROUPTHEORYUTILS_GROUPTHEORYUTILS_H

class intModuleN {
public:
  int k;
  int n;

  intModuleN(int k, int n);
  intModuleN operator*(intModuleN &another);
  intModuleN &operator=(intModuleN &another);
  bool operator==(intModuleN &another);
  void print();
  void input();
};

#endif // GROUPTHEORY_GROUPTHEORY_H
