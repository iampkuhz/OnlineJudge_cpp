/*
 * ScrambleString.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;

class Solution {
public:
	bool *** same;
	bool *** passed;
    bool isScramble(string s1, string s2) {
    	int l = s1.length();
        same = new bool **[l];
        passed = new bool **[l];
        for(int i = 0; i < l; i ++)
        {
        	same[i] = new bool *[l];
        	passed[i] = new bool *[l];
        	for(int j = 0 ; j < l; j ++)
        	{
        		same[i][j] = new bool[l];
        		passed[i][j] = new bool[l];
        		for(int k = 0 ; k < l; k ++){
        			same[i][j][k] = false;
        			passed[i][j][k] = false;
        		}
        	}
        }
        return isSame(s1, s2, 0, l-1, 0);
    }

    bool isSame(string & s1, string & s2, int a1, int a2, int b1)
    {
    	if(a1 == a2) return s1[a1] == s2[b1];
    	if(passed[a1][a2][b1]) return same[a1][a2][b1];

    	bool tsame = false;
    	for(int i = a1 + 1; i <= a2; i ++)
    	{
    		if((isSame(s1, s2, a1, i-1, b1) && isSame(s1, s2, i, a2, b1+i-a1)) ||
    				(isSame(s1, s2, a1, i-1, b1+a2-i+1) && isSame(s1, s2, i, a2, b1))){
    			tsame = true;
    			break;
    		}
    	}
    	passed[a1][a2][b1] = true;
    	same[a1][a2][b1] = tsame;
    	return tsame;
    }

    void test()
    {
    	cout << isScramble("great", "rgtae") << endl;
    	cout << isScramble("great", "reatg") << endl;
    	cout << isScramble("great", "ategr") << endl;
    	cout << isScramble("great", "etgar") << endl;
    }
};



