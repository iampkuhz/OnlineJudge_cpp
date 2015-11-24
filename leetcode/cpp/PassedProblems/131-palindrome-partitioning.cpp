/*
 * 131-palindrome-partitioning.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <string>
#include "memory.h"
using namespace std;

class Solution {
public:
	string str;
	int lenS;
	bool ** pa;

    void initPA()
    {
    	pa = new bool*[lenS];
//    	cout << '0' << endl;
    	for(int i = 0 ; i < lenS; i ++)
    	{
    		pa[i] = new bool[lenS];
    		memset(pa[i], true, sizeof(bool) * lenS);
    	}
//    	cout << '0' << endl;
    	for(int len = 2 ; len <= lenS; len ++)
    		for(int i = 0 ; i < lenS - len + 1; i ++)
    		{
    			/* [i, len+i-1] */
//    			cout << i << len+i-1 << cout << str[i] << str[len+i-1] << endl;
    			if(str[i] == str[len+i-1])
    				pa[i][len+i-1] = pa[i+1][len+i-2];
    			else {
    				pa[i][len+i-1] = false;
    			}
    		}
//    	cout << pa[0][2] << endl;
    }

    /* [b, e] */
    vector<vector<int> > partInt(int b, int e){
    	vector<vector<int> > re;
        for(int i = e ; i > b ; i --)
//        	if(isPalinInt(i, e))
        	if(pa[i][e])
        	{
        		vector<vector<int> > re2 = partInt(b, i-1);
        		if(re2.size() > 0)
        		{
        			for(int j = 0 ; j < re2.size(); j ++){
        				re2[j].push_back(e);
        				re.push_back(re2[j]);
        			}
        		}
        	}
//        if(isPalinInt(b, e))
        if(pa[b][e])
        {
        	vector<int> sv;
        	sv.push_back(e);
        	re.push_back(sv);
        }
        return re;
    }

    vector<vector<string> > partition(string s) {
    	str = s;
    	lenS = s.length();
    	initPA();
    	vector<vector<int> > reI = partInt(0, lenS - 1);
    	vector<vector<string> > re;
    	for(int i = 0 ; i < reI.size(); i ++)
    	{
    		vector<string> one ;
    		int last = 0;
    		for(int j = 0; j < reI[i].size(); j ++)
    		{
    			one.push_back(str.substr(last, reI[i][j]+1 - last));
//    			cout << reI[i][j] + 1 << " ";
    			last = reI[i][j]+1;
    		}
//    		cout << endl;
    		re.push_back(one);
    	}
    	return re;
    }

//    vector<vector<string> > partition2(string s) {
//    	vector<vector<string> > re;
//    	int len = s.length();
//        for(int i = len - 1 ; i > 0 ; i --)
//        	if(isPalin(s, i, len - 1))
//        	{
//        		vector<vector<string> > re2 = partition2(s.substr(0, i));
//        		if(re2.size() > 0)
//        		{
//        			string as = s.substr(i);
//        			for(int j = 0 ; j < re2.size(); j ++){
//        				re2[j].push_back(as);
//        				re.push_back(re2[j]);
//        			}
//        		}
//        	}
//        if(isPalin(s, 0, len - 1))
//        {
//        	vector<string> sv;
//        	sv.push_back(s);
//        	re.push_back(sv);
//        }
//        return re;
//    }
//
//    bool isPalinInt(int b, int e)
//    {
//    	int m = (b + e)/2;
//    	for(int i = b ; i < m; i ++)
//    		if(str[i] != str[b + e - i])
//    			return false;
//    	return true;
//    }
//
//    bool isPalin(string s, int b, int e)
//    {
//    	int m = (b + e)/2;
//    	for(int i = b ; i < m; i ++)
//    		if(s[i] != s[b + e - i])
//    			return false;
//    	return true;
//    }

    void test()
    {
    	vector<vector<string> > re = partition("efe");
    	cout << "end" << endl;
    	for(int i = 0 ; i < re.size() ;i ++)
    	{
    		for(int j = 0 ; j < re[i].size(); j ++)
    			cout << re[i][j] << "," ;
    		cout << endl;
    	}
    }
};


