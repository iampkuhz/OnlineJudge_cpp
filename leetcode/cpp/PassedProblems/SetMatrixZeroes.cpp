/*
 * SetMatrixZeroes.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    	if(matrix.size() < 1 || matrix[0].size() < 1) return;

    	int m = matrix.size(), n = matrix[0].size();
    	bool * a = new bool[m];
    	for(int i = 0 ; i < m; i ++)
    		a[i] = false;
    	bool * b = new bool[n];
    	for(int j = 0; j < n; j ++)
    		b[j] = false;

        for(int i = 0 ; i < m ; i ++)
        	for(int j = 0 ;j  < n ; j ++)
        		if(matrix[i][j] == 0){
        			a[i] = b[j] = true;
        		}
        for(int i = 0 ; i < m ; i ++)
        	for(int j = 0 ;j  < n ; j ++)
        		if(a[i] || b[j]){
        			matrix[i][j] = 0;
        		}
        /*for(int i = 0 ; i < m ; i ++){
        	for(int j = 0 ;j  < n ; j ++){
        		if(a[i] || b[j]){
        			matrix[i][j] = 0;
        		}
        		cout << matrix[i][j] << " ";
        	}
        	cout << endl;
        }*/
    }

    void test()
    {
    	int a[] = {2,3,4, 0}, b[] ={23,2,0,2};
    	vector<int> va(a,a+4), vb(b,b+4);
    	vector<vector<int> > inp;
    	inp.push_back(va);
    	inp.push_back(vb);
    	setZeroes(inp);
    	for(int i = 0 ; i< inp.size(); i ++)
    	{
    		for(int j = 0; j < inp[i].size(); j ++)
    			cout << inp[i][j] << " ";
    		cout << endl;
    	}
    }
};



