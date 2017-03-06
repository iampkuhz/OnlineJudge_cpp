/*
 * 求最长子串长度，子串没有重复元素
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastAP(256,-1);
        int sz = s.length();
        int dup = -1;
        int re = 0;
        for(int i = 0 ; i < sz; i ++){
            int dupi = lastAP[s[i]];
            dup = max(dupi, dup);
            re = max(re, i-dup);
            lastAP[s[i]] = i;
        }
        return re;

    }
};
