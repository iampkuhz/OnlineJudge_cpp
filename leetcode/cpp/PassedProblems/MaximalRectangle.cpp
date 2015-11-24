/*
 * MaximalRectangle.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
    	if(matrix.size() < 1 || matrix[0].size() < 1) return 0;

    	int m = matrix.size(), n = matrix[0].size();
    	vector<int> line;
    	for(int i = 0; i < n + 1; i ++)
    		line.push_back(0);
    	vector<vector<int> > v;
    	for(int i = 0 ; i < m + 1; i ++)
    		v.push_back(line);

    	for(int i = 0 ; i < m; i ++)
    		for(int j = 0; j < n; j ++){
    			if(matrix[i][j] == '0')
    				v[i+1][j+1] = 0;
    			else v[i+1][j+1] = v[i][j+1] + 1;
    		}
    	int mSize = 0;
    	for(int i = 1; i <= m; i ++)
    	{
    		int tmax = largestRectangleArea(v[i]);
    		mSize = mSize > tmax ? mSize : tmax;
    	}
    	return mSize;
    }

    int largestRectangleArea(vector<int> &height) {
    	int max = 0;
    	height.push_back(0);
    	int i = 0;
    	stack<int> s;
    	while(i < height.size())
    	{
    		if(s.empty() || height[s.top()] <= height[i])
    			s.push(i);
    		else{
    			int j = 0;
    			while(s.empty() == false && height[s.top()] >= height[i])
    			{
    				j = s.top();
    				s.pop();
    				//cout << "i:" << i<< " j:" << j<< endl;
    				int size = (s.empty() ? i : (i - s.top() - 1) ) * height[j];
    				max = max > size ? max : size;
    			}
    			s.push(i);
    		}
    		i ++;
    	}
        return max;
    }


    void test()
    {

    }

};



