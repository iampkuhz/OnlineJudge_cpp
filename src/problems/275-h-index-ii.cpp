/*
 * 275-h-index-ii.cpp
 *
 *  Created on: Oct 4, 2015
 *      Author: hanzhe
 */


#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
    	int size = citations.size();
    	if(size <1)
    		return 0;
        int l = 0, r = size - 1;
        while(l <= r){
        	int m = (l + r) / 2;
        	if(citations[m] == size - m)
        		return size - m;
        	else if(citations[m] > size - m)
        		r = m - 1;
        	else l = m + 1;
        }
        return size - l;
    }
};
