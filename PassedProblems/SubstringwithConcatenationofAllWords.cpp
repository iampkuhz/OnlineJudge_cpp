/*
 * SubstringwithConcatenationofAllWords.cpp
 *
 *  Created on: 2014年10月29日
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
    	vector<int> result;
    	map<string, int> wordNr;
    	int lenL = L.size();
    	int lenS = S.size();
    	for(int i = 0 ; i < lenL; i ++)
    	{
    		wordNr[L[i]] ++;
    	}
    	map<string, int> curNr;
    	int thre = lenS - lenL * L[0].size();
    	int wordSize = L[0].size();
    	for(int i = 0 ; i <= thre; i ++)
    	{
    		curNr.clear();
    		int j;
    		for(j = 0; j < lenL; j ++)
    		{
    			string word = S.substr(i + j * wordSize, wordSize);
    			if(wordNr.find(word) == wordNr.end())
    				break;
    			curNr[word] ++;
    			if(curNr[word] > wordNr[word])
    				break;
    		}
    		if(j == lenL)
    			result.push_back(i);
    	}
    	return result;
    }

    void test()
    {
    	vector<string> L;
    	L.push_back("foo");
    	L.push_back("bar");
    	vector<int> result = findSubstring("barfoothefoobarman", L);
    	int size = result.size();
    	for(int i = 0; i < size; i ++)
    		cout << "result:" << result[i] << " " << endl;;
    }
};



