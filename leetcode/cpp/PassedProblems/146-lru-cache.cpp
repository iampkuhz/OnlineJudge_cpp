/*
 * 146-lru-cache.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <tr1/unordered_map>
using namespace std;

class LRUCache{
public:
	class Node{
	public:
		Node * pre;
		Node * next;
		int value;
		int key;
		Node(int k, int v): value(v), key(k), pre(NULL), next(NULL) {}
	};
	Node * head;
	Node * tail;
	std::tr1::unordered_map<int, Node *> key2node;
	int capa;
    LRUCache(int capacity) {
    	capa=capacity;
    	head = tail = NULL;
    }

    int get(int key) {
    	if(key2node.find(key) == key2node.end())
    		return -1;
		// node to front
    	Node2front(key);
    	return key2node[key]->value;
    }

    void set(int key, int value) {
    	if(key2node.find(key) != key2node.end())
    	{
    		// node to front
    		Node2front(key);
    		head->value = value;
    	}
    	else{
    		Node * n = new Node(key, value);
    		key2node[key] = n;
    		n->next = head;
    		n->pre = NULL;
    		if(head != NULL)
    			head->pre = n;
    		else
    			tail = n;
    		head = n;

//    		Node * p = head;
//    		cout << ":";
//    		while(p!= NULL){
//    			cout << p->key << " ";
//    			p = p->next;
//    		}cout<< " taiL:" << tail->key /*<< " tpre:" << tail->pre->key */<< endl;

//    		if(key2node.size() > 1)
//    			cout << "tpre:" << tail->pre->key << endl;
    		// delete last node
    		if(key2node.size() > capa)
    		{
    			int k = tail->key;
    			if(tail->pre != NULL){
//        			cout << "tail pre:" <<  tail->pre->key << endl;
    				tail->pre->next = NULL;
        			tail = tail->pre;
//        			cout << "tail:" << tail->key << endl;
    			}
    			else {
    				head = tail = NULL;
    			}
    			key2node.erase(k);
    		}
//    		cout << head->key << head->value << " " <<tail->key <<  tail->value << endl;

//    		p = head;
//    		cout << ":";
//    		while(p!= NULL){
//    			cout << p->key << " ";
//    			p = p->next;
//    		}cout << endl;

    	}
    }

    void Node2front(int key)
    {
    	Node * n = key2node[key];
    	if(n == head)
    		return;
    	else if(n == tail)
    		tail = tail->pre;

    	n->pre->next = n->next;
    	if(n->next != NULL)
    		n->next->pre = n->pre;

    	n->pre = NULL;
    	n->next = head;
    	head->pre = n;
    	head = n;
    }

};

class Solution
{
public:
	void test()
	{
//    	LRUCache * one = new LRUCache(1);
//    	one->set(2,1);
//    	cout << one->get(2) << endl;
//    	one->set(3,2);
//    	cout << one->get(2) << endl;
//    	cout << one->get(3) << endl;
//
//    	one = new LRUCache(2);
//    	one->set(2,1);
//    	one->set(1,1);
//    	cout << one->get(2) << endl;
//    	one->set(4,1);
//    	cout << one->get(1) << endl;
//    	cout << one->get(2) << endl;


		LRUCache *one = new LRUCache(2);
		one->set(2,1);
		one->set(3,2);
		cout << one->get(3) << endl;
		cout << one->get(2) << endl;
		one->set(4,3);
		cout << one->get(2) << endl;
		cout << one->get(3) << endl;
		cout << one->get(4) << endl;
	}
};

