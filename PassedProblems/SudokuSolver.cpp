/*
 * SudokuSolver.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include "memory.h"
#include "string.h"
using namespace std;

class Solution {
public:
    int map[9][9];
    bool col[9][9], row[9][9], squ[9][9];
    void solveSudoku(vector<vector<char> > &board) {
        memset(col, false, sizeof(col));
        memset(row, false, sizeof(row));
        memset(squ, false, sizeof(squ));
        for(int i = 0 ;i < 9; i ++)
        	for(int j = 0 ; j < 9; j ++){
        		if(board[i][j] != '.'){
        			int v = board[i][j] - '0';
        			int sI = (i/3)*3 + (j/3);
        			col[i][v-1] = true;
        			row[j][v-1] = true;
        			squ[sI][v-1] = true;
        			map[i][j] = v;
        		}
        		else map[i][j] = 0;
        	}
        Dfs(0);

        for(int i = 0 ; i < 9; i ++)
        	for(int j= 0 ; j < 9; j ++)
        		board[i][j] = map[i][j] + '0';
    }

    bool Dfs(int step){
    	if(step >= 81) return true;

    	int c = step/9;
    	int r = step % 9;
    	for(int i = 1; i <= 9; i ++)
    	{
    		if(map[c][r] == 0 && Possible(c, r, i)){
    			int sI = (c/3) * 3 + (r/3);
    			map[c][r] = i;
    			col[c][i-1] = true;
    			row[r][i-1] = true;
    			squ[sI][i-1] = true;

    			bool nextStep = Dfs(step + 1);
    			if(nextStep == true) return true;
    			else {
    				map[c][r] = 0;
        			col[c][i-1] = false;
        			row[r][i-1] = false;
        			squ[sI][i-1] = false;
    			}
    		}
    		else if(map[c][r] > 0 )
    			return Dfs(step + 1);
    	}
    	/*if(step > maxStep)
    	{
    		cout << "failed ,step:" << step << endl;
    		maxStep = step;

        	for(int i = 0 ; i < 9; i ++)
        	{
        		for(int j = 0 ; j < 9; j ++)
        		cout<< map[i][j] ;
        		cout<< endl;

        	}cout << endl << endl;
    	}*/
    	return false;
    }

    bool Possible(int c, int r, int num)
    {
    	int i = c, j = r;
		int v = num - 1;
		int sI = (i/3)*3 + (j/3);

		if(col[i][v] || row[j][v] || squ[sI][v])
			return false;
		return true;

    }

    int maxStep = 0;
    void test(){
    	cout << "begin.." << endl;
    	vector<vector<char> > inp(0, vector<char>(9));
    	string s []= {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};;

    	for(int i = 0 ; i < 9; i ++)
    	{
    		vector<char> t(9);
    		for(int j = 0 ; j < 9; j ++){
    			t[j] = s[i][j];
    		}
    		//cout << "string" << (i+1) << ":" << s[i] << endl;
    		inp.push_back(t);
    	}
    	cout << "inp size:" << inp.size() << endl;
    	solveSudoku(inp);

    	/*for(int i = 0 ; i < 9; i ++)
    	{
    		for(int j = 0 ; j < 9; j ++)
    		cout<< inp[i][j] ;
    		cout<< endl;

    	}*/
    }
};



