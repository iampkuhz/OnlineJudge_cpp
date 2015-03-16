/*
 * GenerateParenthsis.cpp
 *
 *  Created on: 2014年10月7日
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		result.clear();
		Reccur(0, 0, "", n);
		return result;
	}
private:
	vector<string> result;
	void Reccur(int firHalf, int secHalf, string str, int thres)
	{
		if(firHalf < secHalf)
			return;
		if(firHalf == thres)
		{
			while(secHalf < thres){
				str += ')';
				secHalf ++;
			}
			result.push_back(str);
			return;
		}
		Reccur(firHalf, secHalf + 1, str + ")", thres);
		Reccur(firHalf + 1, secHalf, str + "(", thres);
	}

	void test()
	{
		Solution * one = new Solution();
		int size;
		while(cin >> size){
			vector<string> result = one->generateParenthesis(size);
			for(unsigned int i = 0; i < result.size(); i ++)
				cout << result.at(i) << endl;
		}

	}
};



