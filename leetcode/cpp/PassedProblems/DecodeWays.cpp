/*
 * DecodeWays.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int *c;
	bool * f;
    int numDecodings(string s) {

        if(s.length() == 0) return 0;
        if(s.length() == 1 && s[0] == '0') return 0;

        if(s.length() == 1) return 1;

    	c = new int[s.length()];
    	f = new bool[s.length()];
    	for(int i = 0 ; i < s.length(); i ++)
    	{
    		c[i] = 0;
    		f[i] = false;
    	}

    	return Rec(s, s.length() - 1);

    }

    int Rec(string & s, int ind)
    {
    	if(ind < 0) return 1;
    	if(f[ind]) return c[ind];

        int sum = 0;
        if(ind == 0 && s[ind] == '0')
        {
        	sum = 0;
        }
        else if(ind == 0)
        {
        	sum = 1;
        }

        else if(s[ind] == '0')
        {
        	if(s[ind-1] == '1' || s[ind-1] == '2')
        	{
        		sum = Rec(s, ind - 2);
        	}
        	else
        	{
        		sum = 0;
        	}
        }
        else
        {
        	sum = Rec(s, ind - 1);
        	if(s[ind - 1] == '1' || (s[ind - 1] == '2' && s[ind] < '7'))
        	{
        		sum += Rec(s, ind - 2);
        	}
        }
		c[ind] = sum;
		f[ind] = true;
		return sum;
    }

    void test()
    {
    	cout << numDecodings("12") << endl;
    }
};



