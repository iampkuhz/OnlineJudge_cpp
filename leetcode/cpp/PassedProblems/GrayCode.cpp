/*
 * GrayCode.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
    	if(n == 0)
    	{
    		int a[] ={0};
    		vector<int> re(a, a+1);
    		return re;
    	}
    	else if(n == 1)
    	{
    		int a[] = {0, 1};
    		vector<int> re(a,a+2);
    		return re;
    	}
        vector<int> subCode = grayCode(n - 1);
        vector<int> re ;
        int base = 1 << (n - 1);

        for(int i = 0; i < subCode.size(); i ++)
        	re.push_back(subCode[i]);


        for(int i = subCode.size() - 1; i >= 0; i --)
        {
        	re.push_back(base + subCode[i]);
        }

        return re;
    }

    vector<int> grayCode2(int n) {
    	if(n == 0)
    	{
    		int a[] ={0};
    		vector<int> re(a, a+1);
    		return re;
    	}
    	else if(n == 1)
    	{
    		int a[] = {0, 1};
    		vector<int> re(a,a+2);
    		return re;
    	}
        vector<int> subCode = grayCode2(n - 1);
        vector<int> re;
        int base = 1 << (n - 1);

        for(int i = 0; i < base/2; i ++)
        {
        	re.push_back(subCode[ 2 * i]);
        	re.push_back(subCode[ 2 * i] + base);
        	re.push_back(subCode[ 2 * i + 1] + base);
        	re.push_back(subCode[ 2 * i + 1]);
        }
        return re;
    }

    void test()
    {
    	vector<int> re = grayCode(2);
    	for(int i = 0  ; i < re.size(); i ++)
    		cout << re[i] << " " ;
    }
};



