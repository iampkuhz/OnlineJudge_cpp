/*
 * Triangle.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    	int ls = triangle.size();

    	if(ls == 0 ) return 0;
    	if(ls == 1) return triangle[0][0];
    	for(int i = 1; i < ls; i ++)
    	{
    		for(int j = 1; j < i; j ++)
    			triangle[i][j] += triangle[i-1][j] < triangle[i-1][j-1] ?
    					triangle[i-1][j] : triangle[i-1][j-1];
    		triangle[i][0] += triangle[i-1][0];
    		triangle[i][i] += triangle[i-1][i-1];
    	}

    	int min = triangle[ls-1][0];;
    	for(int i = 1 ; i < ls; i ++)
    		min = min < triangle[ls-1][i] ? min : triangle[ls-1][i];
    	return min;
    }

    void test()
    {
    	int a[]={2},c2[]={3,4},c3[]={6,5,7},a4[]={4,1,8,3};
    	vector<int> va1(a,a+1),va2(c2,c2+2), va3(c3,c3+3),va4(a4,a4+4);
    	vector<vector<int> > inp;
    	inp.push_back(va1);
    	inp.push_back(va2);
    	inp.push_back(va3);
    	inp.push_back(va4);
    	cout << minimumTotal(inp) << endl;
    }
};



