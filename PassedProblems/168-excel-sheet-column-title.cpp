/*
 * 168-excel-sheet-column-title.cpp
 *
 *  Created on: Aug 1, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


class Solution {
public:
    string convertToTitle(int n) {
        ostringstream os;
        while(n > 0)
        {
            n --;
        	int l = n % 26;
        	char c = 'A' + l;
        	os << c;
        	n = n/26;
        }
        string s = os.str();
        std::reverse(s.begin(), s.end());
        return s;
    }
    void test(){
    	cout << convertToTitle(12) << endl;
    	cout << convertToTitle(28) << endl;
    	cout << convertToTitle(26) << endl;
    	cout << convertToTitle(72) << endl;
    }
};
