/*
 * NextPermutation.cpp
 *
 *  Created on: 2014年10月30日
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int> &num) {
    	int len = num.size();
    	int i;
    	for(i = len - 2; i >= 0; i --)
    	{
    		if(num[i] < num[i+1])
    			break;
    	}
    	if(i >= 0 )
    	{
    		int j = i+1;
    		while(j+1 < len && num[j+1] > num[i])
    			j++;
    		int tmp = num[i];
    		num[i] = num[j];
    		num[j] = tmp;
    	}
    	int tmp;
		for(int j = i+1; j <= (i+len)/2; j ++){
			tmp = num[j];
			num[j] = num[len + i - j];
			num[len + i - j] = tmp;
		}
    }
    void test(){
    	vector<int> input;
    	for(int i = 0; i < 3; i ++)
    	{
    		int a;
    		int t = 3;
    		input.clear();
    		while(t--)
    		{
    			cin >> a;
    			input.push_back(a);
    		}
	    	nextPermutation(input);
	    	for(int i = 0 ; i < input.size(); i ++)
	    		cout << input[i] << " ";
	    	cout << endl;
    	}

    }
};



