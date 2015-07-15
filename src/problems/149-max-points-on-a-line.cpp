/*
 * 149-max-points-on-a-line.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <tr1/unordered_map>
using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };
class Solution {
public:
    int maxPoints(vector<Point>& points) {
    	if(points.size() < 1)
    		return 0;
        std::tr1::unordered_map<double, int> slopeCnt;
        int size = points.size();
        int re = 0;
        for(int i = 0 ; i < size; i ++){
        	slopeCnt.clear();
        	int vertCnt = 0;
        	int base = 0;
        	for(int j = i; j < size; j ++)
        	{
        		if(points[j].x == points[i].x)
        		{
        			if(points[j].y == points[i].y)
        				base ++;
        			vertCnt ++;
        		}
        		else{
        			double slope = 1.0 * (points[i].y - points[j].y)/ (points[i].x - points[j].x);
        			if(slopeCnt.find(slope) != slopeCnt.end())
        				slopeCnt[slope] ++;
        			else slopeCnt[slope] = 1;
//        			cout << i << j << " " << slope << endl;
        		}
        	}
        	re = re > vertCnt ? re : vertCnt;
        	for(std::tr1::unordered_map<double, int>::iterator it = slopeCnt.begin(); it != slopeCnt.end(); it ++)
        	{
        		re = re > (base + it->second) ? re : (base + it->second);
        	}
        }
        return re;
    }

    void test()
    {
    	Point p[] = {Point(84,250),  Point(0,0),  Point(1,0),  Point(0,-70),  Point(0,-70),  Point(1,-1),  Point(42,90),  Point(-42,-230),  Point(21,10)};
    	vector<Point> ps(p, p+9);
    	cout << maxPoints(ps) << endl;
    }
};


