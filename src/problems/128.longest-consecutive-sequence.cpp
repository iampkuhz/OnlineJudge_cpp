/*
 * 128.longest-consecutive-sequence.cpp
 *
 *  Created on: Jul 11, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <tr1/unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	std::tr1::unordered_set<int> num;
    	for(int i = 0 ; i < nums.size(); i ++)
    		num.insert(nums.at(i));
    	int size = 1;
    	while(num.size() > size)
    	{
    		int a = *(num.begin());
    		num.erase(a);
    		int s = 1, b = 1;
    		while(num.find(a-s) != num.end()){
    			//cout << (a-s) << (num.find(a-s) == num.end()) << endl;
    			num.erase(num.find(a-s));
    			//cout << (a-s) << (num.find(a-s) == num.end()) << endl;
    			s ++;
    		}
    		while(num.find(a+b) != num.end()){
    			//cout << (a+b) << (num.find(a+b) == num.end()) << endl;
    			num.erase(num.find(a+b));
    			//cout << (a+b) << (num.find(a+b) == num.end()) << endl;
    			b ++;
    		}
    		//cout << a << " " << s << " " << b << endl;
    		size = (b + s - 1 > size) ? b + s - 1 : size;
    	}
    	return size;
    }

    void test()
    {
    	int a0 [] ={100, 4, 200, 1, 3, 2};
    	vector<int> a(a0, a0 + 6);
    	cout << longestConsecutive(a);
    }
};


