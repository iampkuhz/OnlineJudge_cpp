/*
 * UniquePathsII.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	int m = obstacleGrid.size() ;
    	if(m < 1) return 0;
    	int n = obstacleGrid[0].size();
    	//cout << m << " " << n << endl;
        int ** p = new int *[m + 1];
        for(int i = 0 ; i <= m ; i ++)
        {
        	p[i] = new int[n+1];
        	for(int j = 0 ; j <= n; j ++)
        		p[i][j] = 0;
        }
    	//cout << m << " " << n << endl;
        p[0][1] = 1;
		for(int i = 1 ; i <= m; i ++)
			for(int j = 1; j <=n ; j ++){
				if(obstacleGrid[i-1][j-1] > 0)
					p[i][j] = 0;
				else p[i][j] = p[i-1][j] + p[i][j-1];
			}
		return p[m][n];
    }

    void test()
    {
    	int a[] ={0,0,0}, b[]={0,1,0};
    	vector<vector<int> > inp;
    	vector<int> va(a,a+3),vb(b,b+3),vc(a,a+3);
    	inp.push_back(va);
    	inp.push_back(vb);
    	inp.push_back(va);
    	cout << uniquePathsWithObstacles(inp) << endl;
    }
};



