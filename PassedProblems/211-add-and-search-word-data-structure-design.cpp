/*
 * 211-add-and-search-word-data-structure-design.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <map>
using namespace std;

class Node{
public:
	map<int,Node*> cn;
	bool isW;
	Node(){
		isW = false;
	}
};
class WordDictionary {
public:
	Node * root = new Node();

    // Adds a word into the data structure.
    void addWord(string word) {
    	if(root == NULL)
    		root = new Node();
    	Node * t = root;
        for(int i = 0 ; i < word.size(); i ++){
        	int ind =  word[i] - 'a';
        	if(t->cn.find(ind) == t->cn.end())
        		t->cn[ind] = new Node();
        	t = t->cn[ind];
        }
        t->isW = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
    	return rec(word, root);
    }
    bool rec(string w, Node * r){
    	if(r == NULL)
    		return false;
    	if(w.length() == 0)
    		return r->isW;
    	int ind = w[0] - 'a';
//    	cout << "sub:" << w.substr(1) << endl;
    	if(w[0] == '.'){
    		for(int i = 0 ; i < 26; i ++)
    			if(r->cn.find(i) != r->cn.end() && rec(w.substr(1), r->cn[i]))
    				return true;
    	}
    	else if(r->cn.find(ind) != r->cn.end()){
    		return rec(w.substr(1), r->cn[ind]);
    	}
    	return false;
    }
};

class Solution{
public:
	void test(){
		WordDictionary d;
//		d.addWord("bad");
//		d.addWord("dad");
//		d.addWord("mad");
//		cout << d.search("pad");
//		cout << d.search("bad") ;
//		cout << d.search(".ad") ;
//		cout << d.search("b..") ;

		d.addWord("at");
		d.addWord("and");
		d.addWord("an");
		d.addWord("add");
		cout << "@" << endl;
		cout << d.search("a");
		cout << "@" << endl;
		cout << d.search(".at");
		d.addWord("bat");
		cout << "@" << endl;
		cout << d.search(".at");
		cout << d.search("an.");
		cout << d.search("a.d.");
		cout << d.search("b.");
		cout << d.search("a.d");
		cout << d.search(".");
	}
};
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


