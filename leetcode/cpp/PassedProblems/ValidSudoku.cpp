/*
 * ValidSudoku.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include "memory.h"
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool col[9][9], row[9][9], squ[9][9];
        memset(col, false, sizeof(col));
        memset(row, false, sizeof(row));
        memset(squ, false, sizeof(squ));
        for(int i = 0 ; i < 9; i ++)
        	for(int j = 0 ; j < 9 ; j ++)
        	{
        		if(board[i][j] == '.') continue;
        		int v = board[i][j] - '1';

        		if(col[i][v]) return false;
        		col[i][v] = true;

        		if(row[j][v]) return false;
        		row[j][v] = true;

        		int sI = (i/3)*3 + (j/3);
        		if(squ[sI][v]) return false;
        		squ[sI][v] = true;
        	}
        return true;
    }
};



