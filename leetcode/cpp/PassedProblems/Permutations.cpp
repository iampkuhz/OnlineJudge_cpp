/*
 * Permutations.cpp
 *
 *  Created on: Mar 5, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > result;
	vector<bool> filled;
	vector<int> cp;
	vector<int> seq;
	int size;
    vector<vector<int> > permute(vector<int> &num) {
    	for(int i = 0 ; i < num.size(); i ++){
    		filled.push_back(false);
    		cp.push_back(num[i]);
    		seq.push_back(0);
    	}
    	//cout << "seq size:" << seq.size()<< endl;
    	size = num.size();
    	Rec(0);
    	return result;
    }

    void Rec(int ind)
    {
    	//cout << ind << " "<< size << endl;
    	if(ind >= size){
    		result.push_back(seq);
    		return;
    	}
    	for(int i = 0 ; i < size; i ++)
    		if(filled[i] == false){
    			filled[i] = true;
    			seq[i] = cp[ind];
    			Rec(ind + 1);
    			filled[i] = false;
    		}
    }

    void test()
    {
    	int a[] = {1,2,3};
    	vector<int> s(a, a + 3);
    	vector<vector<int> > rs = permute(s);
    	for(int i = 0 ; i < rs.size(); i++)
    	{
    		for(int j = 0 ; j < rs[i].size(); j ++)
    			cout << rs[i][j] << " ";
    		cout << endl;
    	}

    }
};



