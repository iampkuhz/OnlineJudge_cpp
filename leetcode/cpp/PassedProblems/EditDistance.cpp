/*
 * EditDistance.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
    	int ** p = new int *[word1.length() + 1];
        for(int i = 0 ; i < word1.length() + 1; i ++){
        	p[i] = new int[word2.length() + 1];
        	for(int j = 0 ; j < word2.length() + 1; j ++)
        		p[i][j] = 0;
        	p[i][0] = i;
        }
        for(int i = 0; i < word2.length() + 1; i ++)
        	p[0][i] = i;
        for(int i = 1; i <= word1.length(); i ++){
        	for(int j = 1; j <= word2.length(); j ++)
        	{
        		if(word1[i-1] == word2[j-1])
        			p[i][j] = p[i-1][j-1];
        		else{
        			p[i][j] = 1 + myMin(myMin(p[i-1][j], p[i][j-1]), p[i-1][j-1]);
        			//cout << "s";
        		}
        		//cout << p[i][j] << " ";
        	}
        	//cout << endl;
        }
        return p[word1.length()][word2.length()];
    }

    int myMin(int a, int b){
    	return a < b ? a : b;
    }

    void test()
    {
    	cout << minDistance("adc", "dca") << endl;
    	cout << minDistance("a", "b") << endl;
    }
};



