/*
 * 221-maximal-square.cpp
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.
 *  Created on: Sep 23, 2015
 *      Author: hanzhe
 */
#include <vector>
#include <iostream>
#include "../dataInit.cpp"
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
    	int r= matrix.size();
    	if(r == 0) return 0;
    	int c = matrix[0].size();
    	if(c == 0 ) return 0;
    	vector<vector<int> > sq(r+1, vector<int>(c+1,0));
    	for(int i = 0 ; i < r; i ++)
    		for(int j = 0; j < c; j ++)
    			sq[i+1][j+1] = matrix[i][j] - '0' + sq[i][j+1] + sq[i+1][j] - sq[i][j];
//    	for(int i = 0 ;i < r+1; i ++){
//    		for(int j = 0 ;j < c+1; j ++)
//    			cout << sq[i][j] << " ";
//    		cout << endl;
//    	}
    	int mi = r < c ? r : c;
    	for(int len = mi; len > 0; len --){
    		int size = len * len;
    		for(int a = 0; a <= r - len; a ++)
    			for(int b = 0; b <= c - len; b ++)
    				if(sq[a+len][b+len] - sq[a][b+len] - sq[a+len][b] + sq[a][b] == size)
    					return size;
    	}
    	return 0;
    }

    void test(){
    	Initer *it = new Initer();
    	string s [] = {"01","10"};
    	vector<vector<char> > vva = it->stringArray2charMatrix(s,2);
    	cout << maximalSquare(vva) << endl;
    }
};



