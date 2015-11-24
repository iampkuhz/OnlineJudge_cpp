/*
 * 242-valid-anagram.cpp
 *
 *  Created on: Oct 4, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
    	vector<int> vs(30, 0);
    	vector<int> vt(30, 0);
    	initV(s, vs);
    	initV(t, vt);
    	for(int i = 0 ; i < 30; i ++)
    		if(vs[i] != vt[i])
    			return false;
    	return true;
    }

    void initV(string s, vector<int> & vs){
    	for(int i = 0 ; i < s.length(); i ++)
    		vs[s[i] - 'a'] ++;
    }

};


