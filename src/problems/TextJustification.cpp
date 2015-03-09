/*
 * TextJustification.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
    	if(words.size() < 1) return words;
        int tL = words[0].size();
        vector<string> line;
        line.push_back(words[0]);
        vector<string> re;
        for(int i = 1; i < words.size(); i ++)
        {
        	if(tL + line.size() + words[i].size() > L){
        		int sp = L - tL;
        		string oneline = MergeWords(line, sp, L);
        		re.push_back(oneline);

        		line.clear();
        		line.push_back(words[i]);
        		tL = words[i].size();
        	}
        	else{
        		tL += words[i].size();
        		line.push_back(words[i]);
        	}
        }
       re.push_back(MergeWords(line, line.size() - 1, L));
       return re;
    }

    string MergeWords(vector<string> & words, int spaceSize, int L)
    {
		string oneline = words[0];
		for(int j = 1 ; j < words.size(); j ++)
		{
			int tN = words.size() - j;
			int tsp = (spaceSize + tN - 1)/tN;
			for(int k = 0; k < tsp; k ++)
				oneline += ' ';
			oneline += words[j];
			spaceSize -= tsp;
		}
		for(int j = oneline.size(); j < L; j ++)
			oneline += ' ';
		return oneline;
    }

    void test()
    {
    	string ss[] = {"This", "is", "an", "example", "of", "text", "justification."};
    	vector<string> words(ss, ss + 7);
    	vector<string> re = fullJustify(words, 16);
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << i << ":\"" << re[i] << "\"  " << re[i].size() << endl;

    	string ss2[] = {"What","must","be","shall","be."};
    	vector<string> words2(ss2, ss2 + 5);
    	vector<string> re2 = fullJustify(words2, 12);
    	for(int i = 0 ; i < re2.size(); i ++)
    		cout << i << ":\"" << re2[i] << "\"  " << re2[i].size() << endl;
    }
};

