/*
 * InterleavingString.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool ** m;
	bool ** pass;
    bool isInterleave(string s1, string s2, string s3) {
    	if(s3.length() != s1.length() + s2.length())
    		return false;
    	//return J(s1, s2, s3, 0, 0, 0);
    	int l3 = s3.length(), l1 = s1.length(), l2 = s2.length();
    	m = new bool*[l1+1];
    	pass = new bool*[l1+1];
    	for(int i = 0 ; i < l1+1; i ++){
    		m[i] = new bool[l2+1];
    		pass[i] = new bool[l2+1];
    		for(int j = 0; j < l2+1; j ++)
    		{
    			m[i][j] = pass[i][j] = false;
    		}
    	}
    	m[0][0] = pass[0][0] = true;
    	return Q(l1, l2, s1, s2, s3);
    }

    bool Q(int l1, int l2, string &s1, string & s2, string & s3)
    {
    	if(pass[l1][l2]) return m[l1][l2];
    	bool re = false;
    	if(l1 > 0 && s1[l1-1] == s3[l1+l2-1])
    		re = Q(l1 - 1, l2, s1, s2, s3);
    	if(re == false && l2 > 0 && s2[l2-1] == s3[l1+l2-1])
    		re = Q(l1, l2-1, s1, s2, s3);
    	pass[l1][l2] = true;
    	m[l1][l2] = re;
    	//cout << l1 << "  " << l2 <<" " << re << endl;
    	return re;
    }

    bool J(string & s1, string & s2, string & s3, int i1, int i2, int i3)
    {
    	if(i3 >= s3.length())
    		 return true;
    	if(i1 < s1.length() && s1[i1] == s3[i3] && J(s1, s2, s3, i1+1, i2, i3+1))
    		return true;
    	if(i2 < s2.length() && s2[i2] == s3[i3] && J(s1, s2, s3, i1, i2+1, i3+1))
    		return true;
    	return false;
    }

    void test()
    {
    	cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    	cout << isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    	cout << isInterleave("", "b", "b") << endl;
    }
};



