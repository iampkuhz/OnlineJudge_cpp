/*
 * ValidPalindrome.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	if(s.length() < 1) return true;

    	int i = 0, j = s.length() -1;
    	while(i < j)
    	{
    		if(isAlphaNum(s[i]) == false)
    		{
    			i++;
    			continue;
    		}
    		else if(isAlphaNum(s[j]) == false)
    		{
    			j --;
    			continue;
    		}
    		else
    		{
    			if(same(s[i], s[j]) == false)
    			{
    				//cout << s[i] << " " << s[j] << endl;
    				return false;
    			}
    			i ++;
    			j --;
    		}
    	}
    	return true;
    }
    bool same(char a, char b)
    {
    	if(a >= 'a') a = a - 'a' + 'A';
    	if(b >= 'a') b = b - 'a' + 'A';
    	return a == b;
    }
    bool isAlphaNum(char c)
    {
    	if((c >= 'a' && c <= 'z') ||
    			(c >= 'A' && c <= 'Z') ||
				(c >= '0' && c <= '9'))
    		return true;
    	return false;
    }

    void test()
    {
    	string a = "A man, a plan, a canal: Panama";
    	cout << isPalindrome(a) << endl;
    	string b = "race a car";
    	cout << isPalindrome(b) << endl;
    }
};



