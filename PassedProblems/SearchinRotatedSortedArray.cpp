/*
 * SearchinRotatedSortedArray.cpp
 *
 *  Created on: 2015年3月2日
 *      Author: hanzhe
 */

#include <iostream>
using namespace std;
class Solution {
public:
    int search(int A[], int n, int target) {
    	return mySearch(A, 0, n-1, target);
    }

    int test(){
    	int A[] = {4, 5,6,7,0,1,2};
    	cout<< search(A, 7, 3) << endl;
    	cout<< search(A, 7, 1) << endl;
    	cout<< search(A, 7, 2) << endl;
    	cout<< search(A, 7, 4) << endl;
    	cout<< search(A, 7, 5) << endl;
    	cout<< search(A, 7, 6) << endl;
    	cout<< search(A, 7, 7) << endl;
    	cout<< search(A, 7, -1) << endl;
    	cout<< search(A, 7, 100) << endl;
    	cout<< search(A, 7, 0) << endl;
    	return -1;
    }
private:
    int mySearch(int A[], int sI, int eI, int tar)
    {
    	if(sI > eI) return -1;
    	if(A[sI] < A[eI])
    		return biSearch(A, sI, eI, tar);
    	int mI = (sI + eI)/2;
    	int mA = A[mI];
    	if(tar == mA) return mI;
    	if(tar >= A[sI]){
    		if(tar < mA) return biSearch(A, sI, mI-1, tar);
    		else if(tar > mA){
    			int i1 = mySearch(A, mI + 1, eI, tar);
    			if(i1 > 0) return i1;
    			else return mySearch(A, sI, mI - 1, tar);
    		}
    	}
    	else if(tar <= A[eI]){
    		if(tar > mA) return biSearch(A, mI + 1, eI, tar);
    		else {
    			int i1 = mySearch(A, mI + 1, eI, tar);
    			if(i1 > 0) return i1;
    			else return mySearch(A, sI, mI - 1, tar);
    		}
    	}
    	return -1;

    }

    int biSearch(int A[], int sI, int eI, int tar)
    {
    	if(sI > eI)
    		return -1;
    	int mI = (sI + eI)/2;
    	if(A[mI] == tar) return mI;
    	else if(A[mI] < tar) return biSearch(A, mI +1, eI, tar);
    	else return biSearch(A, sI, mI - 1, tar);
    }


};


