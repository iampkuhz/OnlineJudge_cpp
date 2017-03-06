/*
 *
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.

Show Company Tags
Show Tags
Show Similar Problems

*/

#include <algorithm>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool myCmp(Interval p1, Interval p2){
        if(p1.start < p2.start) return true;
        if(p1.start > p2.start) return false;
        return (p1.end > p2.end) ? true: false;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        int sz = intervals.size();
        if(sz < 1) return true;
        sort(intervals.begin(), intervals.end(), myCmp);

        int end = intervals[0].end;
        for(int i = 1; i < sz; i ++) {
            if(intervals[i].start < end) return false;
            end = intervals[i].end;
        }
        return true;
    }
};

