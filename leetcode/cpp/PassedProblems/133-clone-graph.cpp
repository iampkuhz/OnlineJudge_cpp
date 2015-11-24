/*
 * 133-clone-graph.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

 struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if(node == NULL)
    		return NULL;
        std::tr1::unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> o2n;
        queue<UndirectedGraphNode *> ons;
        ons.push(node);
        UndirectedGraphNode * n1 = new UndirectedGraphNode(node->label);
        o2n[node]= n1;
        while(ons.size() > 0)
        {
        	UndirectedGraphNode * o = ons.front();
        	ons.pop();
        	UndirectedGraphNode * n = o2n[o];
        	for(int i = 0 ; i < o->neighbors.size(); i ++)
        	{
        		UndirectedGraphNode * nei = o->neighbors.at(i);
        		if(o2n.find(nei) == o2n.end())
        		{
        			UndirectedGraphNode * nnei = new UndirectedGraphNode(nei->label);
        			o2n[nei] = nnei;
        			n->neighbors.push_back(nnei);
        			ons.push(nei);
        		}
        		else{
        			n->neighbors.push_back(o2n[nei]);
        		}
        	}
        }
        return n1;
    }
};


