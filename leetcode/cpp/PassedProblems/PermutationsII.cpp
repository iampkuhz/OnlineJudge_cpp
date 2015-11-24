/*
 * PermutationsII.cpp
 *
 *  Created on: Mar 5, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class myPair{
public:
	int v;
	int c;
	myPair(int v1, int c1){
		v = v1;
		c = c1;
	}
};
class Solution {
public:
	vector<vector<int> > result;
	vector<bool> filled;
	vector<myPair> seq;
	vector<int> one;
	int size;
	int filledNr;
    vector<vector<int> > permuteUnique(vector<int> &num) {
    	sort(num.begin(), num.end());
    	int lastV = num[0], lastC = 1;
    	for(int i = 1 ; i < num.size(); i ++){
    		if(num[i] == lastV)
    			lastC ++;
    		else{
    			myPair *o = new myPair(lastV, lastC);
    			lastV = num[i];
    			lastC = 1;
    			seq.push_back(*o);
    		}
    	}
    	myPair * o = new myPair(lastV, lastC);
    	seq.push_back(*o);

    	/*for(int i = 0 ; i < seq.size(); i ++)
    		cout << seq[i].v << " " << seq[i].c << endl;*/
    	for(int i = 0 ; i < num.size(); i ++){
    		filled.push_back(false);
    		one.push_back(0);
    	}
    	size = num.size();
    	filledNr = 0;

    	Rec(0);
    	return result;
    }

	bool finished = false;
    void Rec(int ind)
    {
    	//cout << "ind:" << ind << endl;
    	if(ind >= seq.size()){
    		result.push_back(one);
    		return;
    	}
    	finished = false;
    	permu(ind, 0, seq[ind].c);
    }

    void permu(int ind, int i, int tc)
    {
    	/*for(int i = 0 ; i < size; i ++)
    		cout << one[i] << " ";*/
    	//cout << "ind:" << ind << " i:" << i << " tc:" << tc << endl;
    	if(tc == 0){
    		Rec(ind + 1);
    		return;
    	}
    	if(i >= size) return;
    	if(size - i >= tc){
    		if(filled[i] == false){
    	    	//cout << "ind2:" << ind << " i:" << i << " tc:" << tc << endl;
        		filled[i] = true;
        		one[i] = seq[ind].v;
        		permu(ind, i+1, tc-1);
        		one[i] = 0;
        		filled[i] = false;
    		}
        	//cout << "ind3:" << ind << " i:" << i << " tc:" << tc << endl;
    		if(size - i > tc){
    			permu(ind, i+1, tc);
    		}
    	}
    }


    void test()
    {
    	int a[] = {3,3,0,0,2,3,2};
    	vector<int> s(a, a + 7);
    	vector<vector<int> > rs = permuteUnique(s);
    	for(int i = 0 ; i < rs.size(); i++)
    	{
    		for(int j = 0 ; j < rs[i].size(); j ++)
    			cout << rs[i][j] << " ";
    		cout << endl;
    	}

    }
};



