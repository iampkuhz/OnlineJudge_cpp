/*
 * RestoreIPAddresses.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	vector<string> re;
    	if(s.length() < 1) return re;

    	vector<int> dots;
    	Rec(s, dots, re, 0);

    	return re;
    }

    void Rec(string & s, vector<int>& dots, vector<string>& re, int ind)
    {

    	if(ind >= s.length() || dots.size() >= 4)
    	{
    		if(ind == s.length() && dots.size() == 4)
    		{
    			string one = s.substr(0, dots[0]);
    			for(int i = 0 ; i < 3; i ++)
    				one += "." + s.substr(dots[i], dots[i+1] - dots[i]);
    			re.push_back(one);
    		}
    		return;
    	}

    	dots.push_back(ind+1);
    	Rec(s, dots, re, ind+1);
    	dots.pop_back();

    	if(ind + 1 < s.length() && s[ind] != '0')
    	{
    		dots.push_back(ind+2);
	    	Rec(s, dots, re, ind+2);
	    	dots.pop_back();
    	}


    	if(ind + 2 < s.length() && s[ind] != '0' && (s[ind] < '2' || (s[ind] == '2' && s[ind+1] < '5') ||
    			(s[ind] == '2' && s[ind+1] == '5' && s[ind+2] < '6')))
    	{
    		dots.push_back(ind+3);
    		Rec(s, dots, re, ind+3);
    		dots.pop_back();
    	}
    }

    void test()
    {
    	//vector<string> re = restoreIpAddresses("25525511135");
    	vector<string> re = restoreIpAddresses("010010");

    	for(int i = 0 ; i < re.size(); i ++)
    	{
    		cout << re[i] << endl;
    	}
    }
};



