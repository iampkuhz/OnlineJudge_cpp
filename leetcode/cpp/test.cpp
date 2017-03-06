e
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include "PassedProblems/235-lowest-common-ancestor-of-a-binary-search-tree.cpp"
#include "/home/hanzhe/Documents/tmp/dashen.c"
dashen.c
using namespace std;

int main(){
int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  std::make_heap (v.begin(),v.end());
  std::cout << "initial max heap   : " << v.front() << '\n';

  std::pop_heap (v.begin(),v.end()); v.pop_back();
  std::cout << "max heap after pop : " << v.front() << '\n';

  v.push_back(99); std::push_heap (v.begin(),v.end());
  std::cout << "max heap after push: " << v.front() << '\n';

  std::sort_heap (v.begin(),v.end());

  std::cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    std::cout << ' ' << v[i];

  std::cout << '\n';
}
