/*
 * 2次过，忘记while循环里t++了，做的很好
 *Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int sz = s.length();
        if(sz < 2) return sz;
        int firP1 = 0, firP2 = -1, lastP = -1;
        for(int i = 1; i < sz; i ++)
            if(s[i] != s[firP1]){
                lastP = firP2 = i; break;
            }
        if(firP2 < 0) return sz;
        int re = 0, t = firP2 + 1;
        while(t < sz){
            if(s[t] == s[firP1] || s[t] == s[firP2]){
                if(s[t] != s[lastP])
                    lastP = t;
            }
            else{
                re = re > (t-firP1) ? re : t-firP1;
                firP1 = lastP;
                firP2 = lastP = t;
            }
            t ++;
        }
        re = re > (sz-firP1) ? re : sz-firP1;
        return re;
    }
};
