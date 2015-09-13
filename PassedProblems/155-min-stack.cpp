/*
 * 155-min-stack.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: hanzhe
 */

#include <iostream>
using namespace std;

class MinStack {
public:
	class Node{
	public:
		int x;
		Node * pre;
		Node * next;
		Node(int x1): x(x1), pre(NULL), next(NULL) {}
	};
	Node * head = new Node(0);
	Node * solidHead = head;
	Node * minNode = NULL;
    void push(int x) {
    	Node * n = new Node(x);
    	n->pre = head;
    	head->next = n;
    	head = n;
    	if(minNode == NULL || minNode->x > x)
    		minNode = n;
    }

    void pop() {
    	if(head->pre != NULL)
    	{
    		head->pre->next = NULL;
        	if(minNode == head)
        		getminNode();
    		head = head->pre;
    		head->next = NULL;
    	}
    }

    int top() {
    	return head->x;
    }

    int getMin() {
    	if(minNode == NULL)
    	{
    		getminNode();
    	}
//    	if(minNode == NULL)
//    		return 0;
    	return minNode->x;
    }
    void getminNode()
    {
    	minNode = solidHead->next;
		Node * t = minNode;
		while(t != NULL)
		{
			if(t->x <= minNode->x)
				minNode = t;
			t = t->next;
		}
    }
};

class Solution
{
public:
	void test()
	{
		MinStack *one = new MinStack();
//		one->push(2);
//		one->push(0);
//		one->push(3);
//		one->push(0);
//		cout << one->getMin() << endl;
//		one->pop();
//		cout << one->getMin() << endl;
//		one->pop();
//		cout << one->getMin() << endl;
//		one->pop();
//		cout << one->getMin() << endl;

		one->push(-10);
		one->push(14);
		cout << one->getMin() << endl;
		cout << one->getMin() << endl;
		one->push(-20);
		cout << one->getMin() << endl;
		cout << one->getMin() << endl;
		cout << one->top() << endl;
		cout << one->getMin() << endl;
		one->pop();
		one->push(10);
		one->push(-7);
		cout << one->getMin() << endl;
		one->push(-7);
		one->pop();
		cout << one->top() << endl;
		cout << one->getMin() << endl;
		one->pop();
	}
};

