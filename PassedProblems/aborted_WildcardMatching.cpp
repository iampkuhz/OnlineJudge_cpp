/*
 * WildcardMatching.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include "memory.h"
using namespace std;

class Solution {
public:
	string s1 = "", s2 = "";
	bool **pa;
    bool isMatch(const char *s, const char *p) {
    	int i = 0;
    	while(s[i] != '\0')
    		s1 += s[i++];
    	i = 0;
    	char lastC = ' ';
    	while(p[i] != '\0'){
    		if(lastC == '*' && p[i] == '*'){
    			i++;
    			continue;
    		}
    		s2 += p[i];
    		lastC = p[i++];
    	}
    	pa = new bool *[s1.length() + 1];
    	for(int i = 0; i < s1.length() + 1; i ++){
    		pa[i] = new bool[s2.length() + 1];
    		for(int j = 0 ; j < s2.length() + 1; j ++)
    			pa[i][j] = false;
    	}

    	//cout << "s1:" << s1.length() << " " << s1 << " s2:" << s2.length() << " " << s2 << endl;;
    	bool re = match(0, 0);
    	//cout << "re:" << re << endl;
    	return re;
    }

    int count =1;
    bool match(int ind1, int ind2)
    {
    	count ++;
    	if(pa[ind1][ind2]) return false;
    	pa[ind1][ind2] = true;

    	//cout << "ind1:" << ind1 << " ind2:" << ind2 << endl;
    	if(ind1 >= s1.length() || ind2 >= s2.length()){
    		if(ind2 == s2.length() && ind1 == s1.length()) return true;
    		return false;
    	}

    	if(s2[ind2] != '*' && s2[ind2] != '?'){
    		if(s2[ind2] == s1[ind1]) return match(ind1 + 1, ind2 + 1);
    		else return false;
    	}

    	else  if(s2[ind2] == '?'){
    		return match(ind1 + 1, ind2 + 1);
    	}
    	else{
    		if(match(ind1, ind2 + 1))
    			return true;
    		if(match(ind1 + 1, ind2 + 1))
    			return true;
    		return match(ind1 + 1, ind2);
    	}
    	return false;
    }

    void test()
    {
    	/*char * a = "aa", * b = "a";
    	cout << isMatch(a, b) << endl;
    	char * a2 = "a*" , * a3 = "aa";
    	cout << isMatch(a, a2) << endl;
    	cout << isMatch(a, a3) << endl;*/
    	//cout << isMatch("aaa", "aa") << endl;
    	//cout << isMatch("aa", "*") << endl;
    	//cout << isMatch("aa", "a*") << endl;
    	//cout << isMatch("ab", "?*") << endl;
    	//cout << isMatch("aab", "c*a*b") << endl;
    	//cout << isMatch("ho", "**ho") << endl;
    	cout << isMatch("babbbaabbaaaaabbababaaaabbbbbbbbbbabbaaaabbababbabaa", "**a****a**b***ab***a*bab") << endl;
    	cout << count << endl;
    }
};



