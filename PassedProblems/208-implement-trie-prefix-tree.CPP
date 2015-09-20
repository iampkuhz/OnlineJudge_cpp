/*
 * 208-implement-trie-prefix-tree.CPP
 *
 *  Created on: Sep 15, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <map>
using namespace std;
/**
 * 如果childNodes采用26维的数组太浪费空间,会runtime error
 */
class TrieNode {
public:
    // 26
	map<int,TrieNode*> childNodes;
	bool isWord;
    TrieNode() {
    	isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
    	TrieNode * t = root;
    	for(int i = 0; i < word.length(); i ++){
        	int ind = word[i] - 'a';
        	if(t->childNodes.find(ind) == t->childNodes.end())
        		t->childNodes[ind] = new TrieNode();
    		t = t->childNodes[ind];
    	}
    	t->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
    	TrieNode * lastNode = Get(word);
    	return lastNode != NULL && lastNode->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
    	TrieNode * lastNode = Get(prefix);
    	return lastNode != NULL;
    }

private:
    TrieNode* root;
    TrieNode * Get(string word){
    	TrieNode * t = root;
    	for(int i = 0 ; i < word.length(); i ++){
        	int ind = word[i] - 'a';
        	if(t->childNodes.find(ind) == t->childNodes.end())
    			return NULL;
    		t = t->childNodes[ind];
    	}
    	return t;
    }
};

class Solution{
public:
	void test(){
		Trie t;
		t.insert("sdf");
		cout << t.search("sdf") << endl;
		cout << t.search("sd2") << endl;
		cout << t.startsWith("sd") << endl;
		cout << t.startsWith("sdf") << endl;
		cout << t.startsWith("sdff") << endl;
		cout << t.startsWith("dff") << endl;
		t.insert("sd2");
		cout << t.search("sdf") << endl;
		cout << t.search("sd2") << endl;
		cout << t.startsWith("sd") << endl;
		cout << t.startsWith("sdf") << endl;
		cout << t.startsWith("sdff") << endl;
		cout << t.startsWith("dff") << endl;
	}
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

