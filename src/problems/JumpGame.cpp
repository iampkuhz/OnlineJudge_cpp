/*
 * JumpGame.cpp
 *
 *  Created on: 2015年3月7日
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
    	if(n == 1) return true;
    	if(A[0] <= 0) return false;
    	int ind = 1, maxN = A[0];
    	while(true)
    	{
    		if(ind >= n-1) return true;
    		if(ind > maxN) return false;
    		int indN = ind + A[ind];
    		maxN = maxN > indN ? maxN : indN;
    		if(ind + 1 <= maxN) ind ++;
    		else return false;
    	}
    }

    void test()
    {
    	int a[] = {2,3,1,1,4};
    	int b [] = {3,2,1,0,4};
    	cout << canJump(a,5) << endl;
    	cout << canJump(b,5) << endl;
    }
};



