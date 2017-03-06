/*
 * 求最少的教室数量安排课程
 * 排序+最小堆维护每个教室的最后空闲时间: https://leetcode.com/discuss/54571/simple-c-solution-sort-min-heap-greedy
 * 我自己用的
 *
 */
#include <vector>
#include <algorithm>
using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct myGreater{
    bool operator()(const int &a, const int &b)const{ return a > b;}
};
class Solution {
public:
    static bool myCmp(Interval i1, Interval i2){
        if(i1.start != i2.start) return i1.start < i2.start ? true : false;
        return i1.end > i2.end ? true : false;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        int sz = intervals.size();
        if(sz < 2) return sz;
        sort(intervals.begin(), intervals.end(), myCmp);
        vector<int> cEnd;
        cEnd.push_back(intervals[0].end);
        make_heap(cEnd.begin(), cEnd.end(), myGreater());
        for(int i = 1 ;  i < sz; i ++){
            // for(int j = 0 ; j < cEnd.size();j ++)
            //     cout << cEnd[j] << " ";
            // cout << " front:" << cEnd.front() << endl;
            if(intervals[i].start >= cEnd.front()){
                pop_heap(cEnd.begin(), cEnd.end(), myGreater());
                cEnd.pop_back();
            }
            cEnd.push_back(intervals[i].end);
            push_heap(cEnd.begin(), cEnd.end(), myGreater());
            // for(int j = 0 ; j < cEnd.size();j ++)
            //     cout << cEnd[j] << " ";
            // cout << " front:" << cEnd.front() << endl;
        }
        return cEnd.size();
    }
};
