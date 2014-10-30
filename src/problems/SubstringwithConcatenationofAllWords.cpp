/*
 * SubstringwithConcatenationofAllWords.cpp
 *
 *  Created on: 2014年10月29日
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
    	int lenL = L.size();
    	int lenS = S.size();
    	bool **occ = new bool *[lenL];
    	for(int i = 0; i < lenL; i ++)
    	{
    		occ[i] = new bool[lenS];
        	memset(occ[i], false, sizeof(bool)*lenS);
    	}
    	int totalL = 0;
    	int * lens = new int[lenL];
    	for(int i = 0 ; i < lenL; i ++)
    	{
    		findSubString(occ[i], S, L[i]);
    		totalL += L[i].length();
    		lens[i] = L[i].length();
    	}
    	/*cout << " ######## " << endl;
    	for(int i = 0 ; i < lenL; i ++)
    	{
    		for(int j = 0; j < lenS; j ++)
    			cout << occ[i][j] << " ";
    		cout << endl;
    	}
    	cout << " ######## " << endl;*/
    	vector<int> result;
    	bool * in = new bool[lenL];
    	memset(in, false, sizeof(bool)*lenL);
    	int start = 0;
    	while(start < lenS - totalL)
    	{
    		for(int j = 0; j < lenL; j ++)
    		{
    			if(occ[j][start] == true)
    			{
    				in[j] = true;
    				bool find = Rec(start + lens[j], in, occ, lenL, 1, lens);
    				if(find)
    					result.push_back(start);
    				//cout <<"j:"<<j<<" s:"<<start<<" "<<find<<endl;
    				in[j] = false;
    			}
    		}
    		start ++;
    	}
    	return result;
    }

    bool Rec(int ind, bool * in, bool ** occur, int size, int k,
    		int * lens)
    {
    	if(k >= size)
    		return true;
    	//cout<<k<<" "<<ind<<endl;
    	for(int i = 0; i < size; i ++)
    		if(in[i] == false && occur[i][ind] == true)
    		{
    			in[i] = true;
    			bool r = Rec(ind + lens[i], in, occur, size, k+1, lens);
    			if(r)
    				return true;
    			in[i] = false;
    		}
    	return false;
    }
    void findSubString(bool * occr, string S,
    		string P)
    {
    	//cout << S << " " << P << endl;
    	int lenP = P.length();
    	int * next = new int[lenP];
    	next[0] = -1;
    	int i = 1;
    	while(i < lenP)
    	{
    		int simL = next[i-1];
    		while(simL >= 0 && P[i-1] != P[simL])
    			simL = next[simL];
    		next[i] = simL + 1;
    		i ++;
    	}
    	/*for(int i = 0 ; i < lenP; i ++)
    		cout << next[i] << " ";
    	cout << endl;*/
    	i = 0;
    	int lenS = S.length();
    	int indP = 0;
    	while(i < lenS)
    	{
    		while(indP >=0 && S[i] != P[indP])
    		{
    			indP = next[indP];
    		}
    		if(indP == lenP-1)
    		{
    			occr[i-indP] = true;
    			indP = next[lenP-1];
    		}
    		else{
    			i++, indP ++;
    		}
    	}
    }
    void test()
    {
    	vector<string> L;
    	L.push_back("foo");
    	L.push_back("bar");
    	vector<int> result = findSubstring("barfoothefoobarman", L);
    	int size = result.size();
    	for(int i = 0; i < size; i ++)
    		cout << "result:" << result[i] << " " << endl;;
    }
};



