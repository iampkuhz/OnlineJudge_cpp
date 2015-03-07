/*
 * MergeIntervals.cpp
 *
 *  Created on: 2015年3月7日
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Interval {
     int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	struct cmp
	{
		bool operator()(const Interval &a, const Interval &b)
		{
			return a.start < b.start || (a.start == b.start && a.end < b.end);
		}
	};
    vector<Interval> merge(vector<Interval> &intervals) {
    	vector<Interval> re;
    	if(intervals.size() < 1) return re;

    	int size = intervals.size();
    	sort(intervals.begin(), intervals.end(), cmp());
    	//qsort(I, size, sizeof(Interval), IntervalComp);
    	/*for(int i = 0 ; i < size; i ++)
    		cout << intervals[i].start << "," << intervals[i].end << "; ";
    	cout << endl;*/
    	int s = intervals[0].start, e = intervals[0].end;
    	for(int i = 1 ; i < size; i ++)
    	{
    		if(intervals[i].start <= e)
    			e = intervals[i].end > e ? intervals[i].end : e;
    		else{
    			Interval * p = new Interval(s, e);
    			re.push_back(*p);
    			s = intervals[i].start;
    			e = intervals[i].end;
    		}
    	}
    	Interval * p = new Interval(s, e);
    	re.push_back(*p);
    	return re;
    }
    void test()
    {
    	Interval a(1,4), b(0,4), c(8,10), d(15,18);
    	vector<Interval> inp;
    	inp.push_back(a);
    	inp.push_back(b);
    	//inp.push_back(c);
    	//inp.push_back(d);
    	vector<Interval> re = merge(inp);
    	for(int i = 0 ; i < re.size() ; i ++)
    		cout << re[i].start << "," << re[i].end  << "; " << endl;
    }
};


