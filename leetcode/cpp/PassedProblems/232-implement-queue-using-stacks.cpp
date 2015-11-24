/*
 * 232-implement-queue-using-stacks.cpp
 *
 * Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack
-- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively.
 You may simulate a stack by using a list or deque (double-ended queue),
 as long as you use only standard operations of a stack.
You may assume that all operations are valid
(for example, no pop or peek operations will be called on an empty queue).

 *  Created on: Sep 28, 2015
 *      Author: hanzhe
 */
#include <stack>
#include <iostream>
using namespace std;
class Queue {
public:
	stack<int> s1, s2;
    // Push element x to the back of queue.
    void push(int x) {
    	s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
    	if(s2.empty())
    		while(!s1.empty()){
    			s2.push(s1.top());
    			s1.pop();
    		}
		s2.pop();
    }

    // Get the front element.
    int peek(void) {
    	if(s2.empty())
    		while(!s1.empty()){
    			s2.push(s1.top());
    			s1.pop();
    		}
    	return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
    	return s2.empty() && s1.empty();
    }
};


