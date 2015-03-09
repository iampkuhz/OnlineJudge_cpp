/*
 * PermutationSequence.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        bool *a = new bool[n];
        int mul = 1;
        for(int i = 1; i <= n; i ++)
        {
        	a[i-1] = false;
        	mul *= i;
        }
        mul /= n;
        string re = "";
        for(int i = 0; i < n; i ++)
        {
        	int t = (k-1)/mul;
        	//cout << k << " " << t << " " << mul << endl;
        	int ai = 0;
        	k -= t * mul;
        	if(n - i - 1 > 0 ) mul /= (n - i - 1);
        	while(true)
        	{
        		//cout << "\t" << ai << " " << t << endl;
        		if(a[ai] == false)
				{
        			t --;
        			if(t < 0){
        				//cout << i << ":" << (ai+1) << endl;
        				a[ai] = true;
        				stringstream ss;
        				string st;
        				ss << ai + 1;
        				ss >> st;
        				re += st;
        				//cout << "re:" << re << " s:" << st << endl;
        				break;
        			}
				}
    			ai ++;
        	}
        }
        return re;
    }

    void test()
    {
    	cout << "***:" << getPermutation(3, 2) << endl;
    	cout << "***:" << getPermutation(3, 6) << endl;
    	cout << "***:" << getPermutation(4, 3) << endl;
    }
};



