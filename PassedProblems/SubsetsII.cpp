/*
 * SubsetsII.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Pair{
public:
	int v;
	int c;
	Pair(int v1, int c1)
	{
		v = v1;
		c = c1;
	}
};

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
    	vector<vector<int> > re;
    	if(S.size() < 1) return re;

        // 1.qsort
    	sort(S.begin(), S.end());

    	// 2. change 2 count pair
    	int lv = S[0];
    	int lc = 1;
    	vector<Pair> ps;
    	for(int i = 1 ; i < S.size(); i ++)
    	{
    		if(S[i] != lv){
    			Pair *one = new Pair(lv, lc);
    			ps.push_back(*one);
    			lv = S[i];
    			lc = 1;
    		}
    		else{
    			lc ++;
    		}
    	}
    	Pair *one = new Pair(lv, lc);
    	ps.push_back(*one);

    	// 3. recursive
    	vector<int> tv;
    	Rec(re, ps, 0, tv);

    	return re;
    }

    void Rec(vector<vector<int> > & re, vector<Pair> & ps, int rInd, vector<int> & tv)
    {
    	if(rInd >= ps.size())
    	{
    		re.push_back(tv);
    		return;
    	}
    	Pair n = ps[rInd];

		Rec(re, ps, rInd + 1, tv);
    	for(int i = 0 ; i < n.c; i ++)
    	{
    		tv.push_back(n.v);
    		Rec(re, ps, rInd + 1, tv);
    	}
    	for(int i = 0 ; i < n.c; i ++)
		{
    		tv.pop_back();
		}

    }

    void test()
    {
    	int a[] = {1,2,2};
    	vector<int> va (a, a+3);

    	vector<vector<int> > re = subsetsWithDup(va);

    	for(int i = 0 ; i < re.size(); i++)
    	{
    		for(int j = 0 ; j < re[i].size(); j ++)
    		{
    			cout << re[i][j] << " ";
    		}
    		cout << endl;
    	}
    }
};



