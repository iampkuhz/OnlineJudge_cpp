/*
 * 200-number-of-islands.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: hanzhe
 */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class intPair{
public:
	int i;
	int j;
	intPair(int ti, int tj): i(ti), j(tj){}
};
class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        if(grid.size() < 1 || grid[0].size() < 1) return 0;
        int row = grid.size();
        int col = grid[0].size();
        queue<intPair*> is;
        vector<vector<char> >& vs(grid);
        for(int i = 0 ; i < row; i++)
        	for(int j = 0 ; j < col; j++)
        		if(grid[i][j] == '1')
        			is.push(new intPair(i,j));
        int re = 0;
        while(is.empty() == false){
        	intPair * ip = is.front();
        	is.pop();
        	int i = ip->i, j = ip->j;
        	if(vs[i][j] != '2'){
        		visitAll(i,j, vs, row, col);
        		re ++;
        	}
        }
        return re;
    }
    void visitAll(int i, int j, vector<vector<char> >& vs, int r, int c){
    	if(i>= 0 && i < r && j >= 0 && j < c && vs[i][j] == '1'){
    		vs[i][j] = '2';
    		visitAll(i-1,j,vs,r,c);
    		visitAll(i+1,j,vs,r,c);
    		visitAll(i,j-1,vs,r,c);
    		visitAll(i,j+1,vs,r,c);
    	}
    }
};
