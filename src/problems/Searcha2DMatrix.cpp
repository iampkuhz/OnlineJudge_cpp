/*
 * Searcha2DMatrix.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    	if(matrix.size() < 1 || matrix[0].size() < 1) return false;

    	int m = matrix.size(), n = matrix[0].size();

    	//cout << m << " n:" << n << endl;
    	return Rec(matrix, 0,0, m, n, target);
    }

    bool Rec(vector<vector<int> > &t, int a, int b, int m, int n, int tar)
    {
    	if(b >= n) return Rec(t, a+1, 0, m, n, tar);
    	if(a >= m) return false;
    	if(t[a][b] == tar) return true;
    	if(t[a][b] > tar) return false;
    	if(b < n-1 && tar < t[a][b+1])
    		return false;
    	if(a < m-1 && tar >= t[a+1][b])
    		return Rec(t, a+1, b, m, n, tar);
    	else return Rec(t, a, b+1, m, n, tar);
    }

    void test()
    {
    	int a[]={1,3,5,7};
    	int b[] = {10, 11, 16, 20};
    	int c[] = {23, 30, 34, 50};
    	vector<int> va(a,a+4), vb(b,b+4), vc(c,c+4);
    	vector<vector<int> > inp;
    	inp.push_back(va);
    	inp.push_back(vb);
    	inp.push_back(vc);
    	cout << searchMatrix(inp, 1) << endl;
    	cout << searchMatrix(inp, 3) << endl;
    	cout << searchMatrix(inp, 7) << endl;
    	cout << searchMatrix(inp, 10) << endl;
    	cout << searchMatrix(inp, 16) << endl;
    	cout << searchMatrix(inp, 11) << endl;
    	cout << searchMatrix(inp, 20) << endl;
    	cout << searchMatrix(inp, 23) << endl;
    	cout << searchMatrix(inp, 34) << endl;
    	cout << searchMatrix(inp, 50) << endl;
    	cout << searchMatrix(inp, 2) << endl;
    	cout << searchMatrix(inp, 31) << endl;
    	cout << searchMatrix(inp, 11) << endl;
    	cout << searchMatrix(inp, -11) << endl;
    	cout << searchMatrix(inp, 6) << endl;



    	int d[] ={2};
    	vector<int> vd(d,d+1);
    	vector<vector<int> > inp2;
    	inp2.push_back(vd);
    	cout << searchMatrix(inp2, 3) << endl;
    }
};



