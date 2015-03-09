/*
 * InsertInterval.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
     int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    	bool newIn = false;
    	int si = newInterval.start, ei = newInterval.end;
    	vector<Interval> re;
    	for(int i = 0 ; i < intervals.size(); i ++ )
    	{
    		int s = intervals[i].start, e = intervals[i].end;
    		if(newIn == false && (! (s > ei || si > e))){
    			si = si > s ? s : si;
    			ei = ei > e ? ei : e;
    		}
    		else{
    			if(newIn == false && s > si){
    				Interval it(si, ei);
    				re.push_back(it);
    				newIn = true;
    			}
    			re.push_back(intervals[i]);
    		}
    	}
    	if(newIn == false){
			Interval it(si, ei);
			re.push_back(it);
    	}
    	return re;
    }

    void test()
    {
    	Interval a(1,3), b(6,9), c(2,5);
    	vector<Interval> inp1;
    	inp1.push_back(a);
    	inp1.push_back(b);
    	vector<Interval> re1 = insert(inp1, c);
    	for(int i = 0 ;  i< re1.size(); i ++)
    		cout << re1[i].start << "," << re1[i].end << ";";
    	cout << endl;

    	Interval d(1,2), e(3,5), f(6,7), g(8,10), h(12,16), k(4,9);
    	vector<Interval> inp2;
    	inp2.push_back(d);
    	inp2.push_back(e);
    	inp2.push_back(f);
    	inp2.push_back(g);
    	inp2.push_back(h);
    	vector<Interval> re2 = insert(inp2, k);
    	for(int i = 0 ;  i< re2.size(); i ++)
    		cout << re2[i].start << "," << re2[i].end << ";";
    	cout << endl;

    	Interval l(1,5), m(2,3);
    	vector<Interval> inp3;
    	inp3.push_back(l);
    	vector<Interval> re3 = insert(inp3, m);
    	for(int i = 0 ;  i< re3.size(); i ++)
    		cout << re3[i].start << "," << re3[i].end << ";";
    	cout << endl;

    }
};



