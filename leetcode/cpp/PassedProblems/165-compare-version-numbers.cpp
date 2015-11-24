/*
 * 165-compare-version-numbers.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: hanzhe
 */


#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        queue<int> vs1 = str2ints(version1);
        queue<int> vs2 = str2ints(version2);
        while(!vs1.empty() && !vs2.empty())
        {
        	if(vs1.front() > vs2.front())
        		return 1;
        	else if(vs1.front() < vs2.front())
        		return -1;
        	vs1.pop();
        	vs2.pop();
        }
        while((!vs1.empty()) && vs1.front() == 0)
        	vs1.pop();
        while((!vs2.empty()) && vs2.front() == 0)
        	vs2.pop();
        if(!vs1.empty())
        	return 1;
        else if(!vs2.empty())
        	return -1;
        return 0;
    }
    queue<int> str2ints(string str){
    	queue<int> re;
    	int len = str.length();
    	string s = "";
    	for(int i = 0 ; i < len ; i ++)
    	{
    		if(str[i] == '.')
    		{
    			if(s.length() < 1)
    				re.push(0);
    			else
    			{
    				istringstream is(s);
    				int v ;
    				is >> v;
    				re.push(v);
    			}
    			s = "";
    		}
    		else
    		{
    			s += str[i];
    		}
    	}
    	if(s.length() > 0)
    	{
			istringstream is(s);
			int v ;
			is >> v;
    		re.push(v);
    	}
    	return re;
    }


};

