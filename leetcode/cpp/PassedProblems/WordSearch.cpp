/*
 * WordSearch.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool ** pass;
    bool exist(vector<vector<char> > &board, string word) {
    	if(word == "" ) return true;
    	int m = board.size(), n = board[0].size();
    	pass = new bool *[m];
    	for(int i = 0 ;  i < m ; i ++)
    	{
    		pass[i] = new bool[n];
    		for(int j = 0 ; j < n; j ++)
    			pass[i][j] = false;
    	}
        for(int i = 0 ; i < m; i ++)
        	for(int j = 0; j < n; j ++)
        		if(board[i][j] == word[0]){
        			pass[i][j] = true;
        			bool find = Find(board, word, i, j, 0, m, n);
        			if(find) return find;
        			pass[i][j] = false;
        		}
        return false;
    }

    bool Find(vector<vector<char> > &board, string word, int a, int b, int ind,
    		int m, int n)
    {
    	if(ind >= word.size() - 1) return true;
    	if(a < m - 1 && !pass[a+1][b] && word[ind + 1] == board[a+1][b]){
    		pass[a+1][b] = true;
			if(Find(board, word, a+1, b, ind+1, m, n))
	    		return true;
    		pass[a+1][b] = false;
    	}
    	if(a > 0 && !pass[a-1][b] && word[ind + 1] == board[a-1][b]){
    		pass[a-1][b] = true;
    		if(Find(board, word, a-1, b, ind+1, m, n))
    			return true;
    		pass[a-1][b] = false;
    	}
    	if(b < n - 1 && !pass[a][b+1] && word[ind + 1] == board[a][b+1]){
    		pass[a][b+1] = true;
    		if(Find(board, word, a, b+1, ind+1, m, n))
    			return true;
    		pass[a][b+1] = false;
    	}
    	if(b > 0 && !pass[a][b-1] && word[ind + 1] == board[a][b-1]){
    		pass[a][b-1] = true;
    		if(Find(board, word, a, b-1, ind+1, m, n))
    			return true;
    		pass[a][b-1] = false;
    	}
    	return false;
    }


    void test()
    {
    	char a[] = "ABCE", b[] = "SFCS", c[] = "ADEE";
    	vector<char> ca(a,a+4), cb(b,b+4), cc(c,c+4);
    	vector<vector<char> > inp;
    	inp.push_back(ca);
    	inp.push_back(cb);
    	inp.push_back(cc);
    	cout << exist(inp, "ABCCED") << endl;
    	cout << exist(inp, "SEE") << endl;
    	cout << exist(inp, "ABCB") << endl;

    	char d[] = "aaaa";
    	vector<char> cd(d,d+4);
    	inp.clear();
    	inp.push_back(cd);
    	inp.push_back(cd);
    	inp.push_back(cd);
    	cout << exist(inp, "aaaaaaaaaaaaa") << endl;
    }
};


