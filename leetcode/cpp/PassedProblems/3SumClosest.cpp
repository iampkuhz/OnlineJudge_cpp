/*
 * 3SumClosest.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
    	int n = num.size();
    	int lessMax = target, MoreMin = target;
    	sort(num.begin(), num.end());
    	for(int i = 0 ; i < n; i ++)
    	{
    		int beg = i +1;
    		int end = n-1;
    		while(beg< end)
    		{
    			int sum = num[i] + num[beg] + num[end];
    			if(sum == target)
    				return target;
    			else if(sum > target)
    			{
    				MoreMin = (MoreMin == target || MoreMin > sum) ? sum : MoreMin;
    				end --;
    			}
    			else
    			{
    				lessMax = (lessMax == target || lessMax < sum) ? sum : lessMax;
    				beg ++;
    			}
    		}
    	}
    	if(lessMax == target) return MoreMin;
    	if(MoreMin == target) return lessMax;
    	return (lessMax + MoreMin > 2 * target) ? lessMax : MoreMin;
    }

    void test()
    {
    	int a[]={-1, 2, 1, -4};
    	vector<int> va(a,a+4);
    	cout << threeSumClosest(va, 1) << endl;
    }
};



