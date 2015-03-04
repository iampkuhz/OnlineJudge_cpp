/*
 * FirstMissingPositive.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {

        for(int i = 0 ; i < n; i ++)
        {
        	if(A[i] == (i+1)) continue;
        	while(A[i] != (i + 1) && A[i] > 0 && A[i] <= n && A[A[i]-1] != A[i])
        	{
        		Swap(A, i, A[i] - 1);
        	}
        	if(A[i] > n || A[i] <= 0) A[i] = 0;
        }

        for(int i = 0 ; i < n; i ++)
        	if(A[i] != (i+1))
        		return (i+1);
        return n + 1;
    }

    void Swap(int A[], int i, int j)
    {
    	int t = A[i];
    	A[i] = A[j];
    	A[j] = t;
    }

    void test()
    {
    	int A[] = {1,2,0};
    	cout << firstMissingPositive(A,3) << endl;;
    	int B[] = {3,4,-1,1};
    	cout << firstMissingPositive(B,4) << endl;
    }
};



