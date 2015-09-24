/*
 * dataInit.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: hanzhe
 */

#include <vector>
#include <string>
using namespace std;
class Initer{
public:
	/**
	 * ["baabab","abaaaa","abaaab","ababba","aabbab","aabbba","aabaab"]
	 * =>
	 *
	 */
	vector<vector<char> > stringArray2charMatrix(string as[], int len){
		vector<vector<char> > re;
		for(int i = 0 ; i < len ; i ++)
			re.push_back(vector<char>(as[i].begin(), as[i].end()));
		return re;
	}
};


