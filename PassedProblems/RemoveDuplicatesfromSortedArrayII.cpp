/*
 * RemoveDuplicatesfromSortedArrayII.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n < 2) return n;
        bool dup = false;
        int re = 1;
        int last = A[0];
        for(int i = 1 ; i < n; i ++)
        {
        	if(A[i] == last){
        		if(!dup){
        			A[re] = A[i];
        			re ++;
        			dup = true;
        		}
        	}
        	else{
        		dup = false;
    			A[re] = A[i];
        		re ++;
        		last = A[i];
        	}
        }
        return re;
    }

    void test()
    {
    	//int a[] = {1,1,1,2,2,3};
    	int a[] = {1,2,2,2};
    	int l = removeDuplicates(a, 4);
    	cout << l << endl;
    	for(int i = 0 ; i < l; i ++)
    		cout << a[i] << " ";
    	cout << endl;
    }
};



