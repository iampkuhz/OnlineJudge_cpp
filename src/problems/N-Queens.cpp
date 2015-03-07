/*
 * N-Queens.cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int *q;
	bool *r, *c, *Bi, *bBi;
	vector<vector<string> > result;
    vector<vector<string> > solveNQueens(int n) {
        q = new int[2*n];
        r = new bool[2*n];
        c = new bool[2*n];
        Bi = new bool[2*n];
        bBi = new bool[2*n];
        for(int i = 0 ; i < 2*n; i ++)
        {
        	q[i] = 0;
        	r[i] = false;
        	c[i] = false;
        	Bi[i] = false;
        	bBi[i] = false;
        }
        Rec(0, n);
        return result;
    }
    void Rec(int tr, int n)
    {
    	if(tr >= n){
    		//cout << "re:" << endl;
    		vector<string> s;
    		for(int i = 0 ; i < n; i ++){
        		string line = "";
        		for(int j = 0 ; j < n; j ++)
        			line += ".";
        		line[q[i]] = 'Q';
        		s.push_back(line);
    		}
    		result.push_back(s);
    		//cout << result.size() << endl;
    		return;
    	}
    	for(int i = 0 ; i < n; i ++)
    		if(!r[i] && !c[i] && !Bi[n-i-1+tr] && !bBi[tr+i])
    		{
    			r[i] = true;
    			c[i] = true;
    			Bi[n-i-1+tr] = true;
            	bBi[tr+i] = true;
    			q[tr] = i;
    			Rec(tr + 1, n);
    			r[i] = false;
    			c[i] = false;
            	Bi[n-i-1+tr] = false;
            	bBi[tr+i] = false;
    		}

    }

    void test()
    {
    	vector<vector<string> > re;
    	re = solveNQueens(5);
		cout << re.size() << endl;
    	for(int i = 0; i < re.size(); i ++)
    	{
    		for(int j = 0; j < re[i].size(); j ++)
    			cout << re[i][j]<< endl;
    		cout << endl;
    	}
    }
};


