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
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        uCand.clear();
        result.clear();
        steps.clear();
        int lastI = -1;
        for(int i = 0 ; i < num.size(); i ++)
        	cout << num[i] << " ";
        cout << endl;

        sort(num.begin(), num.end());

        for(int i = 0 ; i < num.size(); i ++)
        	cout << num[i] << " " ;
        cout << endl;

        for(int i = 0 ; i < num.size(); i ++)
    		uCand.push_back(num[i]);
        //cout << "uCand:" << uCand.size() << endl;
        Dfs(0, target);
        return result;
    }

    void Dfs(int passInd, int remain)
    {
    	//cout << "passInd:" << passInd << " remain:" << remain << endl;
    	if(passInd >= uCand.size() || remain == 0){
    		if(remain == 0){
    			for(int i = 0 ; i < result.size(); i ++)
    			{
    				bool exist = true;
    				for(int j = 0; j < steps.size(); j ++)
    					if(result[i][j] != steps[j]){
    						exist = false;
    						break;
    					}
        			if(exist == true) return;
    			}
				result.push_back(steps);
    		}
    		return;
    	}
    	if(passInd < uCand.size() && remain >= uCand[passInd]){
    		steps.push_back(uCand[passInd]);
    		Dfs(passInd + 1, remain - uCand[passInd]);
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
    	int a[] = {10,1,2,7,6,1,5};
    	vector<int> inp(a, a + 7) ;

    	vector<vector<int> > out = combinationSum2(inp, 8);
    	for(int i = 0 ; i < out.size(); i ++)
    	{
    		cout << "o:";
    		for(int j = 0 ; j < out[i].size(); j ++)
    			cout << out[i][j] << " " ;
    		cout << endl;
    	}
    }
};



