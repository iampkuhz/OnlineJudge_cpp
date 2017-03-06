/*
 *
 *Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].
*/

#include <vector>
#include <queue>
#include <utility>
using namespace std;

class ZigzagIterator {
    queue<pair<vector<int>::iterator, vector<int>::iterator> > lists;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.size() > 0)
            lists.push(make_pair(v1.begin(), v1.end()));
        if(v2.size() > 0)
            lists.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        vector<int>::iterator fir = lists.front().first;
        vector<int>::iterator sec = lists.front().second;
        lists.pop();
        if(fir+1 != sec)
            lists.push(make_pair(fir+1, sec));
        return *fir;
    }

    bool hasNext() {
        return !lists.empty();
    }
};


/*
 * 7次过，写的不好
 */
class ZigzagIterator {
public:
    vector<int> s1;
    vector<int> s2;
    int i1, i2;
    bool firVec;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        s1 = v1;
        s2 = v2;
        i1 = i2 = 0;
        firVec = true;
        if(i1 == s1.size())
            firVec = !firVec;
    }

    int next() {
        int re;
        if(firVec){
            re = s1[i1];
            i1 ++;
            if(i2 < s2.size())
                firVec = !firVec;
        }else{
            re = s2[i2];
            i2 ++;
            if(i1 < s1.size())
                firVec = !firVec;
        }
        return re;
    }

    bool hasNext() {
        return (firVec && i1 < s1.size()) || (!firVec && i2 < s2.size());
    }
};

