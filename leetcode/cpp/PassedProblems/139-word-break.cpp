/*
 * 139-word-break.cpp

 *
 *  Created on: Jul 14, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <string>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include "memory.h"
#include <vector>
using namespace std;

class Solution {
public:


    bool wordBreak(string s, std::tr1::unordered_set<string>& wordDict) {
    	int size = s.length();
    	vector<bool> wordB(s.size() + 1, false);
    	wordB[0] = true;
    	for(int i = 1 ; i <= size; i ++){
    		for(int j = 0; j < i; j ++)
    			if(wordB[j] == true && wordDict.find(s.substr(j, i-j)) != wordDict.end())
    			{
    				wordB[i] = true;
    				break;
    			}
    	}
    	return wordB[size];
    }

    void test()
    {
    	std::tr1::unordered_set<string> set;
    	set.insert("a");
    	set.insert("aa");
    	set.insert("aaa");
    	set.insert("aaaa");
    	set.insert("aaaaa");
    	set.insert("aaaaaa");
    	set.insert("aaaaaaa");
    	cout << wordBreak("baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
    			, set) << endl;
    }
};



