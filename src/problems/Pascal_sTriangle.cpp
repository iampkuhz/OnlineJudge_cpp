/*
 * Pascal_sTriangle.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > re;
    	if(numRows == 0) return re;
    	vector<int> fir;
    	fir.push_back(1);
    	re.push_back(fir);
    	Rec(numRows -1 , re);
    	return re;
    }

    void Rec(int last, vector<vector<int> >& re)
    {
    	if((last--) <= 0) return;
    	int l = re.size();
    	vector<int> next;
    	next.push_back(1);
    	for(int i = 1; i < l; i ++)
    		next.push_back(re[l-1][i] + re[l-1][i-1]);
    	next.push_back(1);
    	re.push_back(next);
    	Rec(last, re);
    }

    void test()
    {
    	vector<vector<int> > re = generate(5);

    	for(int i = 0 ; i < re.size(); i ++)
    	{
    		for(int j = 0 ; j < re[i].size(); j ++)
    			cout << re[i][j] << " ";
    		cout << endl;
    	}
    }
};


