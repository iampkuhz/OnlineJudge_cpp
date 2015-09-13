/*
 * 187-repeated-dna-sequences.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    	vector<string> re;
    	map<int,int> hm;
    	int key = 0;
    	for(int i = 0 ; i< s.size(); i ++)
    	{
    		int v = s[i];
    		v = (v>> 1)&(0x3);
    		key = ((key << 2) & ~(0xfff00000)) | v;
    		if(i < 9)
    			continue;
    		if(hm.find(key) != hm.end() && hm[key] == 1)
    		{
    			re.push_back(s.substr(i-9, 10));
//    			cout << key << " " << hm[key] <<i<< " " << s.substr(i-9,10) << endl;
    			hm[key] = 2;
    		}
    		else if( hm.find(key) == hm.end())
    			hm[key] = 1;
    	}
    	return re;
    }

    void test(){
//    	vector<string> out = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    	vector<string> out = findRepeatedDnaSequences("AAAAAAAAAAAAA");
    	for(int i = 0 ; i< out.size(); i ++)
    		cout << out[i] << endl;
    }
};


