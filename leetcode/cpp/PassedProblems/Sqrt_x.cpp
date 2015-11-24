/*
 * Sqrt_x.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
    	if(x <= 1) return x;
        int re = BiSearch(0, x, x);
        return re;
    }

    int BiSearch(int s , int e , int p)
    {
    	//cout << "s:" << s << " e:" << e << endl;
    	if(s + 1 >= e) return s;
    	int m = (e - s)/2 + s;
    	if((p / m == m) && (m * m == p)) return m;
    	else if(p / m < m) return BiSearch(s, m, p);
    	else return BiSearch(m, e, p);
    }

    void test()
    {
    	cout << sqrt(5) << endl;
    	cout << sqrt(1) << endl;
    	cout << sqrt(4) << endl;
    	cout << sqrt(8) << endl;
    	cout << sqrt(9) << endl;
    	cout << sqrt(123) << endl;
    	cout << sqrt(1223) << endl;
    	cout << sqrt(23) << endl;
    	cout << sqrt(2147395599) << endl;
    }
};



