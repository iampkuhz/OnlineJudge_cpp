/*
 * 174-dungeon-game.cpp
 *
 *  Created on: Aug 9, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include "memory.h"
#include "limits.h"
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int m = dungeon.size();
        if(m < 1) return 0;
        int n = dungeon[0].size();
        int ** left = new int*[m];
        int ** pmin = new int*[m];
        for(int i = 0 ; i < m; i ++)
        {
        	left[i] = new int[n];
        	pmin[i] = new int[n];
        	memset(left[i], 0, sizeof(int));
        	memset(pmin[i], 0, sizeof(int));
        }
        left[0][0] = getL(1,1, dungeon[0][0]);
        pmin[0][0] = getM(1,1, dungeon[0][0]);
        int i =0, j = 0;
//		cout << i << j << pmin[i][j] << left[i][j] << endl;
        for(int skew = 1; skew < m+n-1; skew ++)
        {
        	int i = skew < m ? skew : m-1;
        	int j = skew - i;
        	while(i >= 0 && j < n)
        	{
        		bool cov = true;
        		if(i > 0 ){
        			left[i][j] = getL(left[i-1][j], pmin[i-1][j], dungeon[i][j]);
        			pmin[i][j] = getM(left[i-1][i], pmin[i-1][j], dungeon[i][j]);
        			cov = false;
        			if(j > 0 && getM(left[i][j-1], pmin[i][j-1], dungeon[i][j]) < pmin[i][j])
        			{
        				cov = true;
        			}
        		}
        		if(cov){
        			pmin[i][j] = getM(left[i][j-1], pmin[i][j-1], dungeon[i][j]);
        			left[i][j] = getL(left[i][j-1], pmin[i][j-1], dungeon[i][j]);
        		}
//        		cout << i << j << pmin[i][j] << left[i][j] << endl;
        		i --;
        		j ++;
        	}
        }

        return pmin[m-1][n-1];
    }
    int getL(int nbl, int nbm, int v){
    	if(nbl + v > 0)
    		return nbl + v;
    	return 1;
    }
    int getM(int nbl, int nbm, int v){
    	if(nbl + v > 0)
    		return nbm;
    	return (1 - nbl - v) + nbm;
    }

    void test(){
    	vector<vector<int> > inp;
    	int  a[] ={0,0};
    	vector<int> va(a,a+2);
    	inp.push_back(va);
    	cout << calculateMinimumHP(inp) << endl;
    }
};

