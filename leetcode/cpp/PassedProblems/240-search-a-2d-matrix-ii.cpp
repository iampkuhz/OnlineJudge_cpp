/*
 * 240-search-a-2d-matrix-ii.cpp
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
 *  Created on: Oct 3, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.size() < 1 || matrix[0].size() < 1)
        	return false;
        int rN = matrix.size(), cN = matrix[0].size();
    	int j = cN - 1;
        for(int i = 0 ; i < rN; i ++){
        	while(j >= 0 && matrix[i][j] > target)
        		j --;
        	if(j >= 0 && matrix[i][j] == target)
        		return true;
        	else if(j < 0)
        		return false;
        }
        return false;
    }
};


