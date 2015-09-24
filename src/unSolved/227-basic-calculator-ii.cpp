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
#include <sstream>

using namespace std;
class node{
public:
	int v;
	char t;
	node(int tv, int ti): v(tv), t(ti){}
};
class Solution {
public:
    int calculate(string s) {
        s=replaceAllSpace(s);
        string s1 = step(s, 2);
        string s2 = step(s1, 1);
        istringstream is(s2);
        int re;
        is >> re;
        return re;
    }
    string step(string s, int mode){
        stack<node> st;
        for(int i = 0 ; i< s.size(); i ++){
        	char c = s[i];
        	if(isN(c)){
        		int v = 0;
        		while(i < s.size() && isN(s[i])){
        			v = v * 10 + s[i] - '0';
        			i ++;
        		}
        		i--;
        		node *t = new node(v, 'i');
        		st.push(*t);
        		Cal(st, mode);
//        		outputStack(st);
        	}
        	else{
        		node * t= new node(0, c);
        		st.push(*t);
        	}
        }
        return outputStack(st);
    }

    void Cal(stack<node> & st, int mode){
    	if(st.size() < 3)
    		return;
    	node tp = st.top();
    	st.pop();
    	int tmode = st.top().t == '+' || st.top().t == '-' ? 1:2;
    	if(tmode != mode){
    		st.push(tp);
    		return;
    	}
    	char type = st.top().t;
    	st.pop();
    	node tp3 = st.top();
    	st.pop();
    	int re;
    	switch(type){
    	case '+':
    		re = tp.v + tp3.v;
    		break;
    	case '-':
    		re = tp3.v - tp.v;
    		break;
    	case '*':
    		re = tp3.v * tp.v;
    		break;
    	case '/':
    		re = tp3.v / tp.v;
    		break;
    	}
    	node * nn = new node(re, 'i');
    	st.push(*nn);
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

    string outputStack(stack<node> st){
    	string s = "";
    	while(!st.empty()){
	    	ostringstream ss;
    		if(st.top().t == 'i'){
    	    	ss << st.top().v;
    		}
    		else {
    			ss << st.top().t;
    		}
    		s = ss.str() + s;
    		st.pop();
    	}
    	return s;
    }
    void test(){
    	cout << calculate("3+2*2") << endl;
    	cout << calculate(" 3/2 ") << endl;
    	cout << calculate(" 3+5 / 2 ") << endl;
    	cout << calculate("1-1+1") << endl;
    }
};


