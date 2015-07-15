/*
 * 132-palindrome-partitioning-ii.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: hanzhe
 */


#include <iostream>
#include "memory.h"
using namespace std;

class Solution {
public:
	string str;
	int len;
	bool ** pa;
	int ** ms;

	void initPA()
	{
		pa = new bool*[len];
		ms = new int*[len];
		for(int i = 0 ; i < len ; i ++)
		{
			pa[i] = new bool[len];
			ms[i] = new int[len];
			memset(pa[i], true, sizeof(bool) * len);
			memset(ms[i], -1, sizeof(int)* len);
		}
		for(int l = 2; l <= len ; l ++)
			for(int i = 0 ; i < len -l + 1; i ++)
			{
				pa[i][i+l-1] = (str[i] == str[i+l-1]) ? pa[i+1][i+l-2] : false;
			}
	}
    int minCut(string s) {
        len = s.length();
        str = s;
        initPA();
        return mc(0, len-1);

    }
    /* [s, e] */
    int mc(int s, int e)
    {
    	if(ms[s][e] >= 0)
    		return ms[s][e];
    	int re = e-s;
    	for(int i = s; i < e; i ++)
    	{
    		if(pa[s][i])
    		{
    			int sre = mc(i+1, e) + 1;
    			re = re > sre ? sre : re;
    		}
    	}
    	if(pa[s][e])
    		re = 0;
    	ms[s][e] = re;
//    	cout << s << e << re << endl;
    	return re;
    }

    void test()
    {
    	string s = "leet";
    	cout << minCut(s) << endl;
    }
};

