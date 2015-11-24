/*
 * WildcardMatching.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include "memory.h"
#include "memory.h"
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	int i = 0;
    	int minL = 0;
    	while(p[i++] != '\0')
    		if(p[i] != '*')
    			minL ++;
    	int ls = 0, lp = 0;
    	while(s[ls ++] != '\0');
    	while(p[lp ++] != '\0');

    	if(minL > ls) return false;
    	bool m[2][ls + 1];
    	for(int i = 0 ; i < 2; i ++)
    		for(int j = 0 ; j < ls + 1; j ++)
    			m[i][j] = false;
    	m[0][0] = true;
    	//cout << "ls:" << ls << " lp:" << lp << endl;
    	for(int i = 1 ; i < lp; i ++){
    		for(int j = 0; j < ls; j ++)
    		{
    			//cout << "i:" << i << " j:" << j << endl;
    			if(p[i - 1] == '*' ){
    				//cout << i << j << " m:" << m[i%2][j] << endl;
    				m[i%2][j] = (j > 0 && (m[(i+1)%2][j-1] || m[i%2][j-1])) || m[(i+1)%2][j];
    			}
    			else if(p[i - 1] == '?' && j > 0){
    				//cout << "M:" << endl;
    				m[i%2][j] = m[(i+1)%2][j-1];

    			}
    			else if(j > 0 && p[i - 1] == s[j - 1]){
    				//cout << "N:" << endl;
    				m[i%2][j] = m[(i+1)%2][j-1];
    			}
    			else {
    				//cout << "L:" << endl;
    				m[i%2][j] = false;
    			}

    			//cout << "\"" << m[i%2][j] << "\" ";
    		}
    		//cout << endl;
    	}
    	return m[(lp+1)%2][ls-1];
    }

    void test()
    {
    	/*char * a = "aa", * b = "a";
    	cout << isMatch(a, b) << endl;
    	char * a2 = "a*" , * a3 = "aa";
    	cout << isMatch(a, a2) << endl;
    	cout << isMatch(a, a3) << endl;*/
    	cout << isMatch("aaa", "aa") << endl;
    	//cout << isMatch("aa", "*") << endl;
    	//cout << isMatch("aa", "a*") << endl;
    	//cout << isMatch("ab", "?*") << endl;
    	//cout << isMatch("aab", "c*a*b") << endl;
    	//cout << isMatch("ho", "**ho") << endl;
    	//cout << isMatch("babbbaabbaaaaabbababaaaabbbbbbbbbbabbaaaabbababbabaa", "**a****a**b***ab***a*bab") << endl;
    	//cout << isMatch("abc", "abc*defghijk");
    }
};



