/*
 * Pascal_sTriangleII.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	vector<int> getRow(int rowIndex) {
    	vector<int> re;
    	re.push_back(1);
    	if(rowIndex == 0) return re;
    	Rec(rowIndex -1 , re);
    	return re;
    }

    void Rec(int last, vector<int> & re)
    {
    	if((last--) < 0) return;
    	int l = re.size();
    	vector<int> next;
    	next.push_back(1);
    	for(int i = 1; i < l; i ++)
    		next.push_back(re[i] + re[i-1]);
    	next.push_back(1);
    	re.clear();
    	re.insert(re.end(), next.begin(), next.end());
    	Rec(last, re);
    }

    void test()
    {
    	vector<int> re = getRow(1);

    	for(int i = 0 ; i < re.size(); i ++)
    	{
    			cout << re[i] << " ";
    	}
		cout << endl;
    }
};
