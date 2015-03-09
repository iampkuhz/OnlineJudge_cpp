/*
 * LengthofLastWord.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
    	int i = 0;
    	int re = 0;
    	int last = 0;
        while(s[i] != '\0')
        {
        	if(s[i] == ' '){
        		if(re != 0) last = re;
        		re = 0;
        	}
        	else re ++;
        	i ++;
        }
        if(re == 0)
        	re = last;
        return re;
    }

    void test()
    {
    	char * s = "Hello World";
    	cout << lengthOfLastWord(s) << endl;
    	cout << lengthOfLastWord("a   ") << endl;
    }
};



