/*
 * MinimumPathSum.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
    	if(grid.size() < 1 || grid[0].size() < 1) return 0;
    	int m = grid.size(), n = grid[0].size();
        int ** p = new int * [m];
        for(int i = 0 ;i < m; i ++)
        {
        	p[i] = new int[n];
        	for(int j = 0 ; j < n; j ++)
        		p[i][j] = 0;
        }
        p[0][0] = grid[0][0];
        int s = p[0][0];

        for(int i = 1 ; i < m; i ++)
        {
        	s += grid[i][0];
        	p[i][0] = s;
        }
        s = p[0][0];
        for(int i = 1 ; i < n; i ++)
        {
        	s += grid[0][i];
        	p[0][i] = s;
        }

        for(int i = 1 ;i < m; i ++)
        	for(int j = 1; j < n;j ++)
        	{
        		p[i][j] = p[i-1][j] < p[i][j-1] ? p[i-1][j] : p[i][j-1];
        		p[i][j] += grid[i][j];
        	}
/*
        for(int i = 0 ;i < m; i ++){
        	for(int j = 0; j < n;j ++)
        	{
        		cout << p[i][j] << " ";
        	}cout << endl;
        }*/
        return p[m-1][n-1];
    }

    void test()
    {
    	int a[] ={1,3,2}, b[]={5,3,6}, c[]={2,4,3};
    	vector<vector<int> > inp;
    	vector<int> va(a,a+3),vb(b,b+3),vc(c,c+3);
    	inp.push_back(va);
    	inp.push_back(vb);
    	inp.push_back(vc);
    	cout << minPathSum(inp) << endl;

    }
};



