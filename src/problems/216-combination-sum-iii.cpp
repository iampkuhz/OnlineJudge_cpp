/*
 * 216-combination-sum-iii.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: hanzhe
 */


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
    	vector<vector<int> >  re;
    	stack<int> sel;
    	rec(re, 0, sel, 1, k, n);
    	return re;
    }
    void rec(vector<vector<int> > & re, int sum, stack<int>& sel, int depth, int k, int tar){
//    	cout << "depth:" << depth << " sel:" << sel.size() << " sum:" << sum << endl;
    	if(sel.size() == k && sum == tar){
    		stack<int> ts(sel);
    		vector<int> one;
    		while(!ts.empty()){
    			one.push_back(ts.top());
    			ts.pop();
    		}
    		reverse(one.begin(), one.end());
    		re.push_back(one);
    		return;
    	}
    	if(depth > 9 || sum >= tar || sel.size() >= k)
    		return;
    	sel.push(depth);
    	rec(re, sum + depth, sel, depth+1, k, tar);
    	sel.pop();
    	rec(re, sum, sel, depth+1, k, tar);
    }

    void test(){
    	vector<vector<int> > re = combinationSum3(3,9);
    	for(int i = 0 ; i < re.size(); i ++){
    		for(int j = 0 ; j < re[i].size(); j ++)
    			cout << re[i][j] << " ";
    		cout << endl;
    	}
    }
};
