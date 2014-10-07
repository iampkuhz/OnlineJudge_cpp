/*
 * ValidParentheses.cpp
 *
 *  Created on: 2014年10月7日
 *      Author: hanzhe
 */
#include<iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
    	stack<int> cStack;
    	for(unsigned int i = 0; i < s.length(); i++)
    	{
    		int id = Char2Int(s.at(i));
    		//cerr << id << endl;
    		if(id > 0)
    			cStack.push(id);
    		else{
    			if(cStack.empty())
    				return false;
    			int lastid = cStack.top();
    			if(lastid + id != 0)
    				return false;
    			cStack.pop();
    		}
    	}
    	if(cStack.empty() == false)
    		return false;
    	return true;
    }

    int Char2Int(char c)
    {
    	switch(c){
    	case '(':
    		return 1;
    	case ')':
    		return -1;
    	case '[':
    		return 2;
    	case ']':
    		return -2;
    	case '{':
    		return 3;
    	case '}':
    		return -3;
    	}
    	return 0;
    }
};



