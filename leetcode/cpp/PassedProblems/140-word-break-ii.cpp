/*
 * 140-word-break-ii.cpp
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
	int ** cut;
	int size;
	string ss;
    vector<string> wordBreak(string s, std::tr1::unordered_set<string>& wordDict) {
    	size = s.length();
    	ss = s;
    	cut = new int * [size+1];
    	for(int i = 0 ; i < size + 1; i ++)
    	{
    		cut[i] = new int[size+1];
    		memset(cut[i], -1, sizeof(int) * (size+1));
    	}
        vector<bool> wordB(size, false);
        wordB[0] = true;
        for(int i = 1; i <= size; i ++ )
        {
        	int ind = 0;
        	for(int j = 0; j < i ; j ++)
        		if(wordB[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end())
        		{
        			cut[i][ind] = j;
        			ind ++;
        			wordB[i] = true;
        		}
        }
        vector<string> re;
        bfs(re, size, "");
        return re;
    }

    void bfs(vector<string> & re, int lastInd, string ts)
    {
    	if(lastInd == 0){
    		re.push_back(ts);
    		return;
    	}
    	if(ts != "")
    		ts = " " + ts;
    	for(int i = 0 ; i < size; i ++)
    	{
    		if(cut[lastInd][i] >= 0)
    			bfs(re, cut[lastInd][i], ss.substr(cut[lastInd][i], lastInd - cut[lastInd][i]) + ts);
    		else break;
    	}
    }

    void test()
    {
    	std::tr1::unordered_set<string> set;
    	set.insert("cat");
    	set.insert("cats");
    	set.insert("and");
    	set.insert("sand");
    	set.insert("dog");
    	vector<string> re = wordBreak("catsanddog" , set);
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << re[i] << endl;
    }
};

