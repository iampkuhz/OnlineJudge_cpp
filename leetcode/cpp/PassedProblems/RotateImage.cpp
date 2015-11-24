/*
 * RotateImage.cpp
 *
 *  Created on: Mar 5, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
    	int size = matrix.size();
    	int **p = new int*[size];
        for(int i = 0 ; i < size; i ++){
        	p[i] = new int[size];
        	for(int j = 0; j < size; j ++)
        		p[i][j] = matrix[i][j];
        }

        for(int i = 0 ; i  < size; i ++)
        	for(int j = 0; j < size; j ++)
        	{
        		int x = j;
        		int y = size - 1 - i;
        		matrix[x][y] = p[i][j];
        	}
    }

    void test()
    {
    	int a[] = {1,2,3};
    	int b[] = {4,5,6};
    	int c[] = {7,8,9};
    	vector<vector<int> > inp;
    	vector<int> va(a, a+3), vb(b, b+3), vc(c, c+3);
    	inp.push_back(va);
    	inp.push_back(vb);
    	inp.push_back(vc);
    	rotate(inp);

    	for(int i = 0 ; i < inp.size(); i++){
    		for(int j = 0 ; j < inp.size(); j ++)
    			cout << inp[i][j] << " " ;
    		cout << endl;
    	}
    }
};



