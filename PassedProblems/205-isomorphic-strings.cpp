/*
 * 205-isomorphic-strings.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int * sa = new int[255], * sb = new int[255];
        for(int i = 0 ; i < 255 ; i ++)
        	sa[i] = sb[i] = 0;
        for(int i = 0 ; i < s.length(); i ++)
        {
        	if(sa[s[i] - 0] == 0  && sb[t[i]] == 0){
        		sa[s[i] - 0] = t[i] - 0;
        		sb[t[i]] = s[i];
        	}
        	else if(sa[s[i]] != t[i] || sb[t[i]] != s[i])
        		return false;
        }
        return true;
    }

    void test(){
    	cout << isIsomorphic("ab", "aa") << endl;
    	cout << isIsomorphic("egg", "add") << endl;
    	cout << isIsomorphic("foo", "bar") << endl;
    	cout << isIsomorphic("paper", "title") << endl;
    }
};



