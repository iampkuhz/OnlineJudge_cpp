/*
 * 207-course-schedule.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: hanzhe
 */


#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "memory.h"
#include <queue>
using namespace std;

class Solution {
public:

    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
    	int n = numCourses;
    	vector<vector<int> > reqs(n, vector<int>(0));
    	vector<int> inD(n,  0);
    	for(int i = 0 ; i < prerequisites.size(); i ++){
    		reqs[prerequisites[i].second].push_back(prerequisites[i].first);
    		inD[prerequisites[i].first] ++;
    	}
    	queue<int> emt;
    	for(int i = 0 ; i < n; i ++)
    		if(inD[i] == 0)
    			emt.push(i);
    	while(!emt.empty()){
    		int id = emt.front();
    		emt.pop();
    		for(int i = 0 ; i < reqs[id].size(); i ++){
    			int src = reqs[id][i];
    			inD[src] --;
    			if(inD[src] == 0)
    				emt.push(src);
    		}
    	}
    	for(int i = 0 ; i < n ; i ++)
    		if(inD[i] != 0)
    			return false;
    	return true;
    }

    bool canFinish2(int numCourses, vector<pair<int, int> >& prerequisites) {
    	vector<vector<int> > reqs(numCourses, vector<int>());
    	for(int i = 0 ; i < prerequisites.size(); i ++)
    	{
    		int a = prerequisites[i].first;
    		int b = prerequisites[i].second;
    		reqs[a].push_back(b);
    	}
    	bool * check = new bool[numCourses];
    	memset(check, false, sizeof(bool) * numCourses);
    	for(int i = 0 ; i < numCourses; i ++){
    		if(!check[i]){
    			bool exist = CheckNode(i, reqs, check, numCourses);
    			if(exist == false)
    				return false;
    			check[i] = true;
    		}
    	}
    	return true;
    }

    bool CheckNode(int ind, vector<vector<int> >& reqs, bool * check, int size){
    	bool * visitedNode = new bool[size];
    	set<int> all;
    	memset(visitedNode, false, sizeof(bool) * size);
    	bool re = Dfs(visitedNode, ind, reqs, check, all);
    	for(set<int>::iterator it = all.begin(); it != all.end(); it ++)
    		check[*it] = true;
    	return re;
    }
    bool Dfs(bool* visitedNode, int ind, vector<vector<int> >& reqs, bool * check,
    		set<int>  all){
    	if(check[ind])
    		return true;
//    	cout << ind << " visit:";
//    	for(set<int>::iterator it = all.begin(); it != all.end(); it ++)
//    		cout << *it << " ";
//    	cout << endl;
    	if(visitedNode[ind] == true)
    		return false;
    	if(reqs[ind].size() == 0){
    		return true;
    	}
    	visitedNode[ind] = true;
    	all.insert(ind);
    	vector<int> va = reqs[ind];
    	for(int i = 0 ; i < va.size(); i ++)
    		if(!Dfs(visitedNode, va[i], reqs, check, all))
    			return false;
    	visitedNode[ind] = false;
    	return true;
    }

    void test(){
    	map<int, vector<int> > reqs;
    	vector<int> v1;
    	v1.push_back(1);
    	v1.push_back(2);
    	reqs[2] = v1;
    	reqs[2].push_back(3);
    	vector<int> v2 = reqs[2];
    	cout << v2.size() << endl;
    	v2.push_back(3);
    	cout << reqs[2].size() << endl;

    	vector<pair<int, int> > vp;
    	pair<int, int> pa(0,1), pb(1,0);
    	vp.push_back(pa);
    	cout << canFinish(2, vp) << endl;
    	vp.push_back(pb);
    	cout << canFinish(2, vp) << endl;
    }
};

