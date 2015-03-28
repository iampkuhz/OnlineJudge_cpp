/*
 * DistinctSubsequences.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int **c;
    int numDistinct(string S, string T) {
        int m = S.length(), n = T.length();
        c = new int*[m+1];
        for(int i = 0 ; i < m+1; i++)
        {
        	c[i] = new int[n+1];
        	for(int j = 0 ; j < n+1; j++)
        	{
        		c[i][j] = 0;
        	}
        	c[i][0] = 1;
        }

        for(int i = 1 ; i <= m; i ++ )
        	for(int j = 1 ; j <= n; j ++)
        	{
        		int ct = c[i-1][j];
        		if(S[i-1] == T[j-1])
        			ct += c[i-1][j-1];
        		c[i][j] = ct;
        	}
        /*int re =0;
        for(int i = 0; i <= m; i ++)
        	re += c[i][n];
        return re;*/
        return c[m][n];
    }

    void test()
    {
    	cout << numDistinct("rabbbit", "rabbit") << endl;
    	cout << numDistinct("ccc", "c") << endl;
    	cout << numDistinct("aabb", "ab") << endl;
    }
};



