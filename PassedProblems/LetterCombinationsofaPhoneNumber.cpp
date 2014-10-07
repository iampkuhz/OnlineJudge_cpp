/*
 * LetterCombinationsofaPhoneNumber.cpp
 *
 *  Created on: 2014年10月7日
 *      Author: hanzhe
 */
#include<iostream>
#include<vector>
#include<map>
#include<string.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	result.clear();
    	char * Nr2Alps[10] = {"", "", "abc", "def", "ghi",
    			"jkl", "mno", "pqrs", "tuv", "wxyz"};
    	Reccur(0, "", digits, Nr2Alps);
    	return result;
    }
private:
    vector<string> result;


    void Reccur(unsigned int ind, string str, string digits,
    		char * Nr2Alps[])
    {
    	//cerr << "w:" << str << ";" << digits << ";" <<  endl;
    	if(ind == digits.length())
    	{
    		//cerr << "e:" << str << ";" << digits << ";" <<  endl;
    		result.push_back(str);
    		return;
    	}
    	char c = digits.at(ind);
		//cerr << "c:" << c << ";" << digits << ";" <<  endl;
    	if(c - '0' >= 0 && c - '0' <= 9)
    	{
    		//cerr << Nr2Alps[c-'0'] << endl;
        	char * cand(Nr2Alps[c-'0']);
        	//cout << ";cand:" << cand << endl;
        	int len = strlen(cand);
        	//cerr << "len:" << len << ";cand:" << cand << endl;
        	if(len < 1)
        		Reccur(ind + 1, str, digits, Nr2Alps);
        	else{
            	for(int i = 0 ; i < len; i ++)
            	{
            		string next = str + Nr2Alps[c-'0'][i];
            		//cerr << "next:" << next << endl;
            		Reccur(ind + 1, next, digits, Nr2Alps);
            	}
        	}
    	}
    	else{
    		string next = str + c;
    		Reccur(ind + 1, next, digits, Nr2Alps);
    	}
    }
};



