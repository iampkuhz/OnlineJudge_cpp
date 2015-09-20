/*
 * 210-course-schedule-ii.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: hanzhe
 */

#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
    	vector<pair<int, int> >& ps(prerequisites);
    	vector<int> re;
    	vector<int> inDg(numCourses, 0);
    	vector<vector<int> > base(numCourses, vector<int>(0));
    	for(int i = 0 ; i < ps.size(); i ++){
    		base[ps[i].second].push_back(ps[i].first);
    		inDg[ps[i].first] ++;
    	}
    	queue<int> emt;
    	for(int i = 0 ; i < numCourses; i ++)
    		if(inDg[i] == 0)
    			emt.push(i);
    	while(!emt.empty()){
    		int id = emt.front();
    		re.push_back(id);
    		emt.pop();
    		vector<int> ns = base[id];
    		for(int i = 0 ; i < ns.size(); i ++){
    			inDg[ns[i]] --;
    			if(inDg[ns[i]] == 0)
    				emt.push(ns[i]);
    		}
    	}
    	if(re.size() != numCourses)
    		re.clear();
    	return re;
    }
};


