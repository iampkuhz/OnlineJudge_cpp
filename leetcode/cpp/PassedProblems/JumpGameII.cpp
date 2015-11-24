/*
 * JumpGameII.cpp
 *
 *  Created on: Mar 5, 2015
 *      Author: hanzhe
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
    	if(n == 1) return 0;
    	int *J = new int[n];
    	for(int i = 0 ; i < n; i ++)
    		J[i] = 0;
        int lastI = A[0];
        for(int i = 1 ; i <= lastI && i < n; i ++)
        	J[i] = 1;
        for(int i = 1 ; i < n; i ++)
        	if(A[i]+i > lastI){
        		//cout << "i:" << i << " lastI:" << lastI << " nextI:" << A[i]+i << endl;
        		for(int j = lastI + 1; j <= A[i] + i && j < n; j ++)
        			J[j] = J[i] + 1;
        		/*for(int k = 0 ; k < n; k ++)
        			cout << J[k] << " ";
        		cout << endl;*/
        		lastI = A[i] + i;
        		if(lastI >= (n-1)) return J[n-1];
        	}
        return J[n-1];
    }

    void test()
    {
    	int A[] = {1,2,3};
    	cout << jump(A, 3) << endl;
    }
};


