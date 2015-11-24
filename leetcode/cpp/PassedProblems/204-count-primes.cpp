/*
 * 204-count-primes.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include "math.h"
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n <=2) return 0;
        vector<int> ps;
        ps.push_back(2);
        for(int i = 3; i < n; i += 2)
        {
        	bool p = true;
        	int ma = (int)sqrt(1.0 * i) + 1;
        	for(int j = 0 ; j < ps.size(); j ++){
        		if(ps[j] >= ma)
        			break;
        		if(i % ps[j] == 0){
        			p = false;
        			break;
        		}
        	}
        	if(p) ps.push_back(i);
        }
        return ps.size();
    }
};


