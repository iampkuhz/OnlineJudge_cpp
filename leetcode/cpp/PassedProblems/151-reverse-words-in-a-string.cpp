/*
 * 151-reverse-words-in-a-string.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        stack<string> wstack;
        string w = "";
        for(int i = 0; i < s.length(); i ++)
        {
        	if(s[i] == ' ' && w.length() > 0)
        	{
        		wstack.push(w);
        		w = "";
        	}
        	else if(s[i] != ' '){
        		w = w + s[i];
        	}
        }
        string re = "";
        if(w.length() > 0)
        	re += w;
        while(!wstack.empty())
        {
        	re = re.length() > 0 ? re + " " + wstack.top() : wstack.top();
        	wstack.pop();
        }
        s = re;
    }
};


