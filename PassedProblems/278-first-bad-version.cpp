/*
 * 278-first-bad-version.cpp
 * You are a product manager and currently leading a team to develop a new product.
 * Unfortunately, the latest version of your product fails the quality check.
 * Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad.
Implement a function to find the first bad version. You should minimize the number of calls to the API.
 *  Created on: Nov 26, 2015
 *      Author: hanzhe
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	/**
	 * 两种方法速度一样
	 */
	int firstBadVersion(int n) {
        if(n == 0)
        	return -1;
        int l =1, r = n;
        while(l < r){
        	if(l + 1 >= r){
        		return l == r ? l : (isBadVersion(l) ? l:r);
        	}
        	int m = l  + (r-l) /2;
        	if(isBadVersion(m))
        		r = m;
        	else l = m + 1;
        }
        return l;
    }


//    int firstBadVersion(int n) {
//        return isBad(1, n);
//    }
//    int isBad(int b, int e){
//    	if(b+1 >= e){
//    		if(b == e)
//    			return b;
//    		return isBadVersion(b) ? b : e;
//    	}
//    	int m = (b+1)/2 + e/2;
//    	if(isBadVersion(m))
//    		return isBad(b, m);
//    	return isBad(m+1, e);
//    }
};



