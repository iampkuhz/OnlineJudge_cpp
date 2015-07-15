/*
 * 138-copy-list-with-random-pointer.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <tr1/unordered_map>
#include <queue>
using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
struct RandomListNode {
     int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(head == NULL)
    		return NULL;
    	std::tr1::unordered_map<RandomListNode *, RandomListNode *> o2n;
    	queue<RandomListNode *> os;
    	std::tr1::unordered_map<RandomListNode *, int> visited;
    	RandomListNode * n1 = new RandomListNode(head->label);
    	os.push(head);
    	o2n[head] = n1;
    	visited[head] = 1;
    	while(os.size() > 0)
    	{
    		RandomListNode * ofr = os.front();
    		RandomListNode * nfr;
    		os.pop();
    		if(o2n.find(ofr) == o2n.end())
    		{
    			nfr = new RandomListNode(ofr->label);
    		}
    		else nfr = o2n[ofr];
    		RandomListNode * onext = ofr->next;
    		if(onext != NULL)
    		{
    			RandomListNode * nnext = o2n.find(onext) == o2n.end() ?
    					new RandomListNode(onext->label) : o2n[onext];
    			o2n[onext] = nnext;
    			if(visited.find(onext) == visited.end())
    			{
    				visited[onext] = 1;
    				os.push(onext);
    			}
    			nfr->next = nnext;
    		}
    		RandomListNode * orand = ofr->random;
    		if(orand != NULL)
    		{
    			RandomListNode * nrand = o2n.find(orand) == o2n.end() ?
    					new RandomListNode(orand->label) : o2n[orand];
    			o2n[orand] = nrand;
    			if(visited.find(orand) == visited.end())
    			{
    				visited[orand] = 1;
    				os.push(orand);
    			}
    			nfr->random = nrand;
    		}
    	}
    	return n1;
    }
};


