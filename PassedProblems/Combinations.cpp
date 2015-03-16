/*
 * Combinations.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > re;
    vector<vector<int> > combine(int n, int k) {
    	if(k == 0 || k > n) return re;
    	vector<int> seq;
    	Rec(n, k, 1, seq);
    	return re;
    }
    void Rec(int n , int k, int ind, vector<int> &seq)
    {
    	if(seq.size() >= k){
    		re.push_back(seq);
    		return;
    	}
    	if(ind > n) return;
    	if(seq.size() + n - ind + 1< k) return;

    	Rec(n, k, ind + 1, seq);
    	seq.push_back(ind);

    	Rec(n, k, ind + 1, seq);
    	seq.pop_back();
    }

    void test()
    {

    	vector<vector<int> > res = combine(4,2);
    	for(int i = 0 ; i < res.size(); i ++)
    	{
    		for(int j = 0 ; j < res[i].size(); j ++)
    			cout << res[i][j] << " ";
    		cout << endl;
    	}
    }
};



