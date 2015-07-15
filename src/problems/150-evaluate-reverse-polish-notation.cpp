/*
 * 150-evaluate-reverse-polish-notation.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	stack<int> nums;
    	for(int i = 0 ; i < tokens.size(); i ++)
    	{
    		string s = tokens[i];
    		if(s == "+" || s == "-" || s == "*" || s == "/")
    		{
    			int o1 = nums.top();
    			nums.pop();
    			int o2 = nums.top();
    			nums.pop();
    			switch(s[0]){
    			case '+':
    				nums.push(o1 + o2);break;
    			case '-':
    				nums.push(o2 - o1);break;
    			case '*':
    				nums.push(o1 * o2);break;
    			case '/':
    				nums.push(o2 / o1);break;
    			}
    		}
    		else{
    			istringstream str(s);
    			int i;
    			str >> i;
    			nums.push(i);
    		}
    	}
    	return nums.top();
    }
};


