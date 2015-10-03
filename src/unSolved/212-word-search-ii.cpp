/*
 * 212-word-search-ii.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "../dataType/dataInit.cpp"
using namespace std;

class Node{
public:
	Node ** os;
	Node * f;
	char c;
	int cnt;
	bool isW;
	Node(char tc): c(tc), os(new Node*[26]), isW(false), f(NULL), cnt(0){}
	Node(char tc, Node* tf): c(tc), os(new Node*[26]), isW(false), f(tf), cnt(0){}
};
class Trie{
public:
	Node * root;
	Trie(){
		root = new Node('0');
	}
	void insert(string w){
		Node * t = root;
		t->cnt ++;
		for(int i = 0 ; i < w.size(); i ++){
			int ci = w[i] - 'a';
			if(t->os[ci] == NULL)
				t->os[ci] = new Node(w[i], t);
			t = t->os[ci];
			t->cnt ++;
		}
		t->isW = true;
	}
};
class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
    	vector<string> re;
    	int r = board.size();
    	if(r == 0) return re;
    	int c = board[0].size();
    	if(c == 0) return re;

    	Trie *t = new Trie();
    	for(int i = 0 ; i < words.size(); i ++)
    		t->insert(words[i]);
    	for(int i = 0 ; i < r; i ++)
    		for(int j = 0 ; j < c; j ++){
//    			cout << "i:" << i << " j:" << j << endl;
    			find(board, i,j, t->root, re, r, c, 1);
    		}
		return re;
    }
    void find(vector<vector<char> >& board, int i, int j, Node * tRoot, vector<string>& re, int r, int c, int depth){
//    	cout << i << " j:" << j << " str:" << Node2Str(tRoot, true)<<tRoot->cnt<<endl;
    	if(tRoot == NULL || i < 0 || i >= r || j < 0 || j >= c || tRoot->cnt < 1)
    		return;
    	tRoot = tRoot->os[board[i][j] - 'a'];
//    	cout << "n2s:" << Node2Str(tRoot, true) << " " << depth << endl;
    	if(tRoot == NULL)
    		return;
    	if(tRoot->isW){
    		string s = Node2Str(tRoot, false);
    		re.push_back(s);
    	}
    	find(board, i+1, j, tRoot, re, r, c, depth+1);
    	find(board, i-1, j, tRoot, re, r, c, depth+1);
    	find(board, i, j-1, tRoot, re, r, c, depth+1);
    	find(board, i, j+1, tRoot, re, r, c, depth+1);
    }
    string Node2Str(Node * tRoot, bool test){
    	string s = "";
		while(tRoot != NULL && tRoot->f != NULL){
			s = tRoot->c + s;
			if(!test)
				tRoot->cnt --;
			tRoot = tRoot->f;
		}
		return s;
    }

    void test(){
    	Initer *init = new Initer();
    	string ss[] = {"baabab","abaaaa","abaaab","ababba","aabbab","aabbba","aabaab"};
    	const char * ssw[] = {"bbaabaabaaaaabaababaaaaababb","aabbaaabaaabaabaaaaaabbaaaba","babaababbbbbbbaabaababaabaaa","bbbaaabaabbaaababababbbbbaaa","babbabbbbaabbabaaaaaabbbaaab","bbbababbbbbbbababbabbbbbabaa","babababbababaabbbbabbbbabbba","abbbbbbaabaaabaaababaabbabba","aabaabababbbbbbababbbababbaa","aabbbbabbaababaaaabababbaaba","ababaababaaabbabbaabbaabbaba","abaabbbaaaaababbbaaaaabbbaab","aabbabaabaabbabababaaabbbaab","baaabaaaabbabaaabaabababaaaa","aaabbabaaaababbabbaabbaabbaa","aaabaaaaabaabbabaabbbbaabaaa","abbaabbaaaabbaababababbaabbb","baabaababbbbaaaabaaabbababbb","aabaababbaababbaaabaabababab","abbaaabbaabaabaabbbbaabbbbbb","aaababaabbaaabbbaaabbabbabab","bbababbbabbbbabbbbabbbbbabaa","abbbaabbbaaababbbababbababba","bbbbbbbabbbababbabaabababaab","aaaababaabbbbabaaaaabaaaaabb","bbaaabbbbabbaaabbaabbabbaaba","aabaabbbbaabaabbabaabababaaa","abbababbbaababaabbababababbb","aabbbabbaaaababbbbabbababbbb","babbbaabababbbbbbbbbaabbabaa"};
    	vector<string> sv(ssw, ssw+7);
    	vector<vector<char> > b = init->stringArray2charMatrix(ss, 7);
    	vector<string> re = findWords(b, sv);
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << "re:" << re[i] << endl;
    }
};


