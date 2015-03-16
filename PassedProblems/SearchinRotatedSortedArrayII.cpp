/*
 * SearchinRotatedSortedArrayII.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;
class Solution {
public:
    bool search(int A[], int n, int target) {
        if(A == NULL || n == 0) return false;
        for(int i = 0 ; i < n; i ++)
            if(A[i] == target) return true;
        return false;

    }
};



