/*
 * 224-basic-calculator.cpp
 *Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
 *  Created on: Sep 24, 2015
 *      Author: hanzhe
 */
#include <stack>
#include <iostream>
using namespace std;
class node{
public:
	int v;
	char type;
	node(int tv, char tt): v(tv), type(tt) {}
};
class Solution {
public:
    int calculate(string s) {
        stack<node> st;
        for(int i = 0 ; i < s.size(); i ++){
        	char c = s[i];
        	if(c == ' ')
        		continue;
        	if(isN(c)){
        		int v = 0;
        		while(i < s.size() && (isN(s[i]) || s[i]==' ')){
        			if(s[i] != ' ')
        				v = v* 10 + s[i] - '0';
        			i ++;
        		}
        		i --;
        		node *t = new node(v, 'i');
        		st.push(*t);
    			StackPOP(st, false);
        	}
        	else if(c == ')'){
    			StackPOP(st, true);
    			StackPOP(st, false);
        	}
        	else{
        		node *t = new node(0, c);
        		st.push(*t);
        	}
//        	cout << "top:" << st.top().v << " " << st.top().type << endl;
        }
        while(st.size() > 1)
        	StackPOP(st, false);
        return st.top().v;
    }
    void StackPOP(stack<node> & st, bool brackedEnd){
    	node tp = st.top();
    	st.pop();
    	if(tp.type == '(')
    		return;
    	if(st.empty()){
    		st.push(tp);
    		return;
    	}
    	node tp2 = st.top();
    	st.pop();
    	if(brackedEnd && tp2.type == '('){
    		st.push(tp);
    		return;
    	}
    	else if(!brackedEnd && tp2.type == '('){
    		st.push(tp2);
    		st.push(tp);
    		return;
    	}
		node tp3 = st.top();
		st.pop();
		int nv = tp3.v + tp.v;
		if(tp2.type == '-')
			nv = tp3.v - tp.v;
		node * t = new node(nv, 'i');
		st.push(*t);
		if(brackedEnd)
			StackPOP(st, true);
    }
    bool isN(char c){
    	return c >='0' && c<='9';
    }

    void test(){
    	cout << calculate("1 + 1") << endl;
    	cout << calculate(" 2-1 + 2 ") << endl;
    	cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    	cout << calculate("(7)-(0)+(4)") << endl;
    }
};



