/*
 * SearchInsertPosition.cpp
 *
 *  Created on: 2015年3月2日
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	return bS(A, 0, n-1, target);
    }

    int bS(int A[], int sI, int eI, int tar)
    {
    	//cout << sI << " e:" << eI << " tar:" << tar << endl;
    	if(sI >= eI -1 ){
    		if(tar > A[eI]) return eI + 1;
    		else if(tar == A[eI]) return eI;
    		else if(tar > A[sI]) return sI + 1;
    		else return sI;
    	}
    	int mI = (sI + eI)/2;
    	int mA = A[mI];
    	if(mA == tar) return mI;
    	else if(mA > tar) return bS(A, sI, mI - 1, tar);
    	else return bS(A, mI + 1, eI, tar);
    }

    void test(){

    	int A[] = {1,3,5,6};
    	cout << searchInsert(A, 6, 5) << endl;
    	cout << searchInsert(A, 6, 2) << endl;
    	cout << searchInsert(A, 6, 7) << endl;
    	cout << searchInsert(A, 6, 0) << endl;
    }
};


