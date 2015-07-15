/*
 * 130.surrounded-regions.cpp
 *
 *  Created on: Jul 12, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include "memory.h"
//#include "test/char_matrix.cpp"
using namespace std;

class Solution {
public:
	int row, col;
	bool ** in;

    void Paint2P(int r, int c, vector<vector<char> >& b)
    {
    	if(c >= col || c < 0 || r>= row || r < 0 || in[r][c] == true)
    		return;
//    	cout << r << c << endl;
    	in[r][c] = true;
    	if(b[r][c] == 'O')
    	{
    		b[r][c] = 'P';
    		//cout << 'o' << r << c << endl;
    		if(r > 0 && in[r-1][c] == false){
    			Paint2P(r-1, c, b);
    		}
    		if(r < row -1 && in[r+1][c] == false){
    			Paint2P(r+1, c, b);
    		}
    		if(c < col -1 && in[r][c+1] == false){
    			Paint2P(r, c+1, b);
    		}
    		if(c > 0 && in[r][c-1] == false){
    			Paint2P(r, c-1, b);
    		}
    	}
    }

    void solve(vector<vector<char> >& board) {
    	row = board.size();
    	if(row < 1)
    		return;
    	col = board[0].size();
    	if(col < 1)
    		return;
//    	cout << row << col << endl;
    	in = new bool *[row];
    	for(int i = 0 ; i < row ; i ++)
    	{
    		in[i] = new bool[col];
//    		memset(in[i], false, sizeof(bool) * col);
    		for(int j = 0 ;j < col; j ++)
    			in[i][j] = false;
    	}

    	/* 1. start from all margin element, put 'O' region to 'P' */
    	for(int i = 0 ; i < row; i ++)
    	{
			Paint2P(i, 0, board);
			Paint2P(i, col-1, board);
    	}
    	for(int j = 0; j < col; j ++)
    	{
			Paint2P(0, j, board);
			Paint2P(row-1, j, board);
    	}

    	/* 2. coloring all except 'P' to 'X', all 'P' to 'O' */
    	for(int i = 0; i < row; i ++)
    		for(int j = 0 ; j < col; j ++)
    		{
    			if(board[i][j] == 'P')
    				board[i][j] = 'O';
    			else board[i][j] = 'X';
    		}
    	return;
    }

    void test()
    {
//    	char_matrix all = new char_matrix();
//    	solve(all.getVectorVector());

    	char a[] = {'O', 'O'}, b[] = {'O', 'O'};
    	vector<char> va(a,a+2), vb(b,b+2);
    	vector<vector<char> > v;
    	v.push_back(va);
    	v.push_back(vb);
    	solve(v);
    	for(int i = 0 ; i < 2; i ++){
    		for(int j = 0 ; j < 2; j ++)
    			cout<< v[i][j];
    		cout << endl;
    	}
    }
};


