/*
 * 4Sum.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
    	vector<vector<int> > re;
    	sort(num.begin(), num.end());

    	set<vector<int> > res;
    	int size = num.size();
    	for(int i = 0 ; i < size; i ++)
    	{
    		for(int j = i + 1; j < size; j ++)
    		{
    			int beg = j +1;
    			int end = size-1;

    			while(beg < end)
    			{
    				int sum = num[i]+num[j]+num[beg]+num[end];
    				if(sum == target)
    				{
    					vector<int> one;
    					one.push_back(num[i]);
    					one.push_back(num[j]);
    					one.push_back(num[beg]);
    					one.push_back(num[end]);
    					res.insert(one);
    					beg ++;
    					end --;
    				}
    				else if(sum < target)
    					beg ++;
    				else end --;
    			}
    		}
    	}
    	set<vector<int> >::iterator it = res.begin();
    	while(it != res.end())
    	{
    		re.push_back(*it);
    		it ++;
    	}
    	return re;
    }

    void test()
    {
    	int a[] ={1, 0, -1, 0 ,-2, 2};
    	vector<int> va(a,a+6);
    	vector<vector<int> > re = fourSum(va, 0);

    	for(int i = 0 ; i < re.size();i ++)
    	{
    		for(int j = 0 ;j < re[i].size(); j++)
    			cout << re[i][j] << " ";
    		cout << endl;
    	}

    }
};


