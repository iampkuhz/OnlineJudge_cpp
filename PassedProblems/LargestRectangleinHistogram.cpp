/*
 * LargestRectangleinHistogram.cpp
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
    	int a[] = {2,1,5,6,2,3};
    	int b[] = {4,2,0,3,2,5};
    	vector<int> va(a,a+6);
    	cout << largestRectangleArea(va) << endl;
    }
};



