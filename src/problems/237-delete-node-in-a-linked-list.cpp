/*
 * 237-delete-node-in-a-linked-list.cpp
 * Write a function to delete a node (except the tail) in a singly linked list,
 *  given only access to that node.
 *  Created on: Oct 3, 2015
 *      Author: hanzhe
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    void deleteNode(ListNode* node) {
    	if(node == NULL)
    		return;
    	node->val = node->next->val;
    	node->next = node->next->next;
    }
};

