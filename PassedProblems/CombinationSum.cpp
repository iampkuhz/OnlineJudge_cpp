/*
 * CombinationSum.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > result;
    vector<int> uCand;
    vector<int> steps;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        uCand.clear();
        result.clear();
        steps.clear();
        int lastI = -1;
        /*for(int i = 0 ; i < candidates.size(); i ++)
        	cout << candidates[i] << " " ;
        cout << endl;*/
        sort(candidates.begin(), candidates.end());
        /*for(int i = 0 ; i < candidates.size(); i ++)
        	cout << candidates[i] << " " ;
        cout << endl;*/
        for(int i = 0 ; i < candidates.size(); i ++)
        	if(candidates[i] != lastI){
        		uCand.push_back(candidates[i]);
        		lastI = candidates[i];
        	}
        //cout << "uCand:" << uCand.size() << endl;
        Dfs(0, target);
        return result;
    }

    void Dfs(int passInd, int remain)
    {
    	//cout << "passInd:" << passInd << " remain:" << remain << endl;
    	if(passInd >= uCand.size() || remain == 0){
    		if(remain == 0)
    			result.push_back(steps);
    		return;
    	}
    	if(passInd < uCand.size() && remain >= uCand[passInd]){
    		steps.push_back(uCand[passInd]);
    		Dfs(passInd, remain - uCand[passInd]);
    		steps.pop_back();

    		Dfs(passInd + 1, remain);
    	}
    	/*else {
    		for(int i = 0 ; i < steps.size(); i ++)
    			cout << steps[i] << " ";
    		cout << "lastInd:" << passInd << " remain:" << remain << endl;
    	}*/
    }


    void test()
    {
    	int a[] = {8,7,4,3};
    	vector<int> inp(a, a + 4) ;

    	vector<vector<int> > out = combinationSum(inp, 11);
    	for(int i = 0 ; i < out.size(); i ++)
    	{
    		cout << "o:";
    		for(int j = 0 ; j < out[i].size(); j ++)
    			cout << out[i][j] << " " ;
    		cout << endl;
    	}
    }
};



