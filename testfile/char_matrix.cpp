/*
 * char_matrix.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class char_matrix{
public :
	/**
	 * AAAA
	 * BBBB
	 * CCCC
	 * DDDD
	 */
	char **p;
	int count = 0;
	int wid = 0;
	vector<vector<char> > vvp;
	char_matrix(){
		ifstream in("testfile/130.test1");
		string str;
		count = 0 ;
		wid = 0;
		while(in)
		{
			getline(in, str);
			if(str.length() > 0){
				count ++;
				wid = wid > str.length() ? wid : str.length();
			}
		}
		p = new char *[count];
		for(int i = 0 ; i < count; i ++)
			p[i] = new char[wid];

		in = ifstream("/home/hanzhe/git/OnlineJudge_cpp/testfile/130.test1");
		int i = 0;
		while(in)
		{
			getline(in, str);
			vector<char> vp;
			if(str.length() > 0){
				for(int j = 0 ; j < str.length(); j ++)
				{
					p[i][j] = str[j];
					vp.push_back(str[j]);
				}
			}
			i ++;
			vvp.push_back(vp);
		}
	}

	char ** getMatrix()
	{
		return p;
	}

	vector<vector<char> > & getVectorVector()
	{
		return vvp;
	}

	int getColumn(){
		return wid;
	}

	int getRow(){
		return count;
	}
};


