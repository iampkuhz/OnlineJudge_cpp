/*
 * SortColors.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: hanzhe
 */

#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int a= 0, b = n - 1;
        int j = 0;
        while(j <= b)
        {
    		while(A[a] == 0)
    			a ++;
    		while(A[b] == 2)
    			b --;
    		while(a > j) j ++;
    		if(j > b) break;
        	//cout << a<< " " << j << " " << b <<endl;
        	if(A[j] == 0){
        		A[j] = A[a];
        		A[a] = 0;
        	}
        	else if(A[j] == 2){
        		A[j] = A[b];
        		A[b] = 2;
        	}
        	else j ++;
        	/*for(int i = 0 ; i < n; i ++)
        		cout << A[i] << " " ;
        	cout << endl;*/
        }
    }

    void test()
    {
    	int a[] = {1,2,0,1,2,1,0,1,1,0,2,1,2,1,0,1,1,0,0,2,0};
    	sortColors(a, 21);
    	for(int i = 0 ; i < 21; i ++)
    		cout << a[i] << " ";

    }
};


