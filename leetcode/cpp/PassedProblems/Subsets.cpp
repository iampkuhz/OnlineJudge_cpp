/*
 * Subsets.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > re;
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> seq;
        Rec(0, seq, S);
        return re;
    }
    void Rec(int ind, vector<int> seq, vector<int> & S)
    {
    	if(ind >= S.size())
    	{
    		re.push_back(seq);
    		return;
    	}
    	Rec(ind + 1, seq, S);

    	seq.push_back(S[ind]);
    	Rec(ind + 1, seq, S);
    }

    void test()
    {
    	int a[] = {1,2,3};
    	vector<int> inp(a, a+3);
    	vector<vector<int> > res = subsets(inp);
    	for(int i = 0 ; i < res.size(); i ++)
    	{
    		for(int j = 0 ; j < res[i].size(); j ++)
    			cout << res[i][j] << " ";
    		cout << endl;
    	}
    }
};
