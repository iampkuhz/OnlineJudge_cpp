/*
 * MinimumWindowSubstring.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include "memory.h"
using namespace std;

class Solution {
public:

    string minWindow(string S, string T) {
    	if(T.length() == 0) return "";
    	int * subS = new int[128], *subT = new int[128];
    	memset(subS, 0, sizeof(int)*128);
    	memset(subT, 0, sizeof(int)*128);

    	for(int i = 0 ; i < T.length(); i ++)
    		subT[T[i]] ++;
    	int s = 0, e = 0, mins = 0, mine = 0;
    	bool find = false;

    	subS[S[0]] ++;
    	while(e < S.length())
    	{
			//cout << "e:" << e << " s:" << s << endl;
    		if(satisfied(subS, subT)){
    			//cout << "find e:" << e << " s:" << s << endl;
    			if(e - s < mine - mins || !find){
    				mins = s;
    				mine = e;
    			}
    			find = true;
    			if(s < e){
    				subS[S[s]] --;
    				s ++;
    			}
    			else{
    				e ++;
    				if(e < S.length())
    					subS[S[e]] ++;
    			}
    		}
    		else{
    			e ++;
    			if(e < S.length())
    				subS[S[e]] ++;
    		}
    	}
    	if(find)
    		return S.substr(mins, mine - mins + 1);
    	else return "";
    }

    bool satisfied(int * s, int * t)
    {
    	for(int i = 0 ; i < 128; i ++)
    		if(s[i] < t[i])
    			return false;
    	return true;
    }

    void test()
    {
    	cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    }
};


