/*
 * UniquePaths.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: hanzhe
 */

#include <iostream>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int **p = new int *[m + 1];
        for(int i = 0 ; i <= m; i ++)
        {
        	p[i] = new int[n + 1];
        	for(int j = 0 ; j <= n; j ++)
        		p[i][j] = 0;
        }
        p[0][1] = 1;
        for(int i = 1 ; i <= m; i ++)
        	for(int j = 1; j <=n ; j ++)
        		p[i][j] = p[i-1][j] + p[i][j-1];
        return p[m][n];
    }

    void test()
    {
    	cout << uniquePaths(2,4) << endl;
    	cout << uniquePaths(3,3) << endl;
    }
};


