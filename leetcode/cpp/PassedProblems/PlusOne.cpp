/*
 * PlusOne.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	int *a = new int[digits.size() +1];
    	int add = 0;
        for(int i = digits.size() - 1 ;i >= 0; i --)
        {
        	a[i+1] = digits[i] + add;
        	if(i == digits.size() - 1) a[i+1] ++;
        	add = a[i+1] /10;
        	a[i+1] = a[i+1] % 10;
        }
        if(add > 0){
        	a[0] = 1;
        	vector<int> re(a, a+digits.size() + 1);
        	return re;
        }
        else{
        	vector<int> re(a+1, a+digits.size() + 1);
        	return re;
        }
    }

    void test()
    {
    	int a[] = {1,2,4,2,9}, b[]={9,9,9,9,9};
    	vector<int> inp(b, b+5);
    	vector<int> re = plusOne(inp);
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << re[i] << " ";
    }
};



