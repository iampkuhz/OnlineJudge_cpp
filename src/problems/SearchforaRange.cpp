/*
 * SearchforaRange.cpp
 *
 *  Created on: 2015年3月2日
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
    	vector<int> res;
    	//cout << "n:" << n << " tar:" << target << endl;
    	int i1 = tarMinInd(A, 0, n - 1, target);
    	if(i1 < 0){
    		res.push_back(-1);
    		res.push_back(-1);
    	}
    	else{
    		int i2 = tarMaxInd(A, 0, n - 1, target);
    		res.push_back(i1);
    		res.push_back(i2);
    	}
    	return res;
    }

    void test(){
    	int A[] = {5,7,7,8,8,10};
    	vector<int> res = searchRange(A, 6, 8);
    	cout <<"A:" <<  res[0] << " " << res[1] << endl;
    	res.clear();
    	res = searchRange(A, 6, 9);
    	cout <<"A2:" <<  res[0] << " " << res[1] << endl;
    	res.clear();
    	res = searchRange(A, 6, 10);
    	cout <<"A3:" <<  res[0] << " " << res[1] << endl;
    	res.clear();
    	res = searchRange(A, 6, 7);
    	cout <<"A4:" <<  res[0] << " " << res[1] << endl;
    	res.clear();
    	res = searchRange(A, 6, 5);
    	cout <<"A5:" <<  res[0] << " " << res[1] << endl;
    }
private:
    int tarMinInd(int A[], int sI, int eI, int tar)
    {
    	//cout << "s:" << sI << " e:" << eI << " tar::" << tar << endl;
    	if(sI > eI) return -1;
    	if(sI >= eI - 1){
    		if(A[sI] == tar) return sI;
    		if(A[eI] == tar) return eI;
    		else return -1;
    	}
    	int mI = (sI + eI)/2;
    	int mA = A[mI];
    	if(mA < tar) return tarMinInd(A, mI + 1, eI, tar);
    	else return tarMinInd(A, sI, mI, tar);
    }
    int tarMaxInd(int A[], int sI, int eI, int tar)
    {
    	//cout << "s:" << sI << " e:" << eI << " tar::" << tar << endl;
    	if(sI > eI) return -1;
    	if(sI >= eI - 1){
    		if(A[eI] == tar) return eI;
    		if(A[sI] == tar) return sI;
    		else return -1;
    	}
    	int mI = (sI + eI)/2;
    	int mA = A[mI];
    	if(mA > tar) return tarMaxInd(A, sI, mI-1, tar);
    	else return tarMaxInd(A, mI, eI, tar);
    }
};



