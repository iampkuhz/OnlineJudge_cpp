/*
 * 227-basic-calculator-ii.cpp
 * Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
 *  Created on: Sep 24, 2015
 *      Author: hanzhe
 */
#include <string>
#include <stack>
#include <iostream>

using namespace std;
class Solution {
public:
    int calculate(string s) {
    	s = replaceAllSpace(s);
    	stack<int> vs;
    	stack<char> os;
    	for(int i = 0 ; i < s.size(); i ++){
        	char c = s[i];
        	if(isN(c)){
        		int v = 0;
        		while(i < s.size() && isN(s[i])){
        			v = v * 10 + s[i] - '0';
        			i ++;
        		}
        		i--;
        		vs.push(v);
        	}
        	else{
        		while(!os.empty() && oLevel(os.top()) >= oLevel(c))
        			Cal(vs, os);
        		os.push(c);
        	}
    	}
    	while(os.size() > 0)
    		Cal(vs, os);
    	return vs.top();
    }
    void Cal(stack<int>& vs, stack<char>& os){
    	int vt = vs.top();
    	vs.pop();
    	int vt2 = vs.top();
    	vs.pop();
    	char c = os.top();
    	os.pop();
    	switch(c){
    	case '-':
    		vs.push(vt2 - vt);
    		break;
    	case '+':
    		vs.push(vt2 + vt);
    		break;
    	case '*':
    		vs.push(vt2 * vt);
    		break;
    	case '/':
    		vs.push(vt2 / vt);
    		break;
    	}
    }
    int oLevel(char c){
    	if(c == '-' || c == '+')
    		return 1;
    	return 2;
    }
    bool isN(char c){
    	return c >='0' && c <='9';
    }

    string replaceAllSpace(string s){
    	int b = s.find(" ", 0);
    	while(b != -1){
    		s.replace(b, 1, "");
    		b = s.find(" ", b);
    	}
    	return s;
    }
    void test(){

    	cout << calculate("3+2*2") << endl;
    	cout << calculate(" 3/2 ") << endl;
    	cout << calculate(" 3+5 / 2 ") << endl;
    	cout << calculate("1-1+1") << endl;
    	cout << calculate("1*2-3/4+5*6-7*8+9/10") << endl;
    }
};


