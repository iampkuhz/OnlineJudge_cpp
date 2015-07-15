/*
 * 134-gas-station.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int size = gas.size();
    	for(int i = 0 ; i < gas.size(); i ++)
    		gas[i] = gas[i] - cost[i];
    	int cnt = 0, sum = 0;
    	int i;
    	for(i = 0 ; i < 2*size ; i ++)
    	{
    		sum += gas[i%size];
			cnt ++;
    		if(sum < 0)
    		{
    			cnt = 0;
    			sum = 0;
    		}
    		else{
    			if(cnt >= size)
    				break;
    		}
    	}
    	if(sum >= 0 && cnt >= size) return (i+1-size) % size;
    	return -1;
    }
    /* failed*/
    int canCompleteCircuitDP(vector<int>& gas, vector<int>& cost) {
    	int size = gas.size();
    	int ** sum;
    	sum = new int * [size];
    	for(int i = 0 ; i < size ; i ++){
    		sum[i] = new int [size];
    		sum[i][(i+1)%size] = gas[i] - cost[i];
    	}
    	for(int len = 2; len < size; len ++)
    		for(int i = 0; i < size; i ++)
    		{
    			sum[i][(i+len-1)%size] = sum[i][(i+1)%size] + sum[(i+1)%size][(i+len-1)%size];
    		}
    	for(int i = 0 ; i < size; i ++)
    		if(sum[i][(i+1)%size] >= 0)
    			return i;
    	return -1;
    }

    void test()
    {
    	vector<int> a, b;
    	a.push_back(5);
    	b.push_back(5);
    	cout << canCompleteCircuit(a,b) << endl;
    }
};


