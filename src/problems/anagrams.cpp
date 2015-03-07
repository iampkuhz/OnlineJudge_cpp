/*
 * anagrams.cpp
 *
 *  Created on: Mar 5, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:

    vector<string> anagrams(vector<string> &strs) {
    	int size;
    	vector<string> re;
    	size = strs.size();
    	map<string, int> m;
        for(int i = 0 ; i < size; i ++)
        {
        	string s = strs[i];
        	sort(s.begin(), s.end());
        	if(m.find(s) == m.end())
        		m[s] = i;
        	else{
        		if(m[s] >= 0){
        			int j = m[s];
        			re.push_back(strs[j]);
        			m[s] = -1;
        		}
        		re.push_back(strs[i]);
        	}
        }
        return re;
    }


};



