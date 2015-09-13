#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "stdlib.h"
#include "stdio.h"
using namespace std;

class Solution {
public:
	static bool compare(int a, int b)
	{
		return a>b;
	}

	vector<int> mySort(vector<int> inp)
	{
		sort(inp.begin(), inp.end(), compare);
		return inp;
	}

	static int qCompare(const void * a, const void * b)
	{
		return *((int*)a) - *((int*)b);
	}

	void myQSort(int* inp, int n)
	{
		qsort(inp, n, sizeof(int), qCompare);
		return;
	}

	void test(){
		int a[] = {3,21,42,2,4};
		vector<int> va (a, a+5);
		va = mySort(va);
		for(int i = 0 ; i < 5; i ++)
			cout << va[i] <<" " ;
		cout << endl;

		myQSort(a,5);
		for(int i = 0 ; i < 5; i ++)
			cout << a[i] <<" " ;
		cout << endl;
	}
};
