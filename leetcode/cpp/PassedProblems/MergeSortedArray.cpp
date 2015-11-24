/*
 * MergeSortedArray.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	if(n == 0) return;
    	queue<int> q;
    	int a = 0, b = 0;
    	while(a < m && b < n){
			if(q.empty() == false && q.front() <= B[b]){
				q.push(A[a]);
				A[a++] = q.front();
				q.pop();
			}
			else if(A[a] <= B[b])
				a  ++;
			else {
				q.push(A[a]);
				A[a++] = B[b++];
			}
    	}
    	if(a < m){
    		for(int i = a; i < m; i ++)
    			q.push(A[i]);
    	}
    	while(q.empty() == false || b < n){
    		//cout << "b:" << b << endl;
    		if(b < n && (q.empty() || q.front() > B[b]))
    			A[a++] = B[b++];
    		else {
    			A[a++] = q.front();
    			q.pop();
    		}
    	}
    }

    void test()
    {
    	int a[] = {1,2,4,5,6};//{1,2,4,5,7};
    	int b[] = {3};//{2,4,5,6,9,10};

    	merge(a, 5, b, 1);
    	for(int i = 0 ; i < 6; i ++)
    		cout << a[i] << " ";
    	cout << endl;
    }
};



