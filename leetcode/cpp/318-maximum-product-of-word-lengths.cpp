/*
 *
 *Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <utility>
using namespace std;

/*
 * 看答案，一次过，用int代替bitset更好用
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int sz = words.size();
        if(sz == 0) return 0;
        vector<int> ws(sz,0);
        for(int i = 0  ; i < sz; i ++)
            for(char c : words[i])
                ws[i] |= 1 << (c-'a');
        int re = 0;
        for(int i = 0; i < sz; i ++)
            for(int j = i+1; j < sz; j ++)
                if((ws[i] & ws[j]) == 0)
                    re = re > words[i].length()* words[j].length() ? re : words[i].length()* words[j].length();
        return re;
    }
};



/*
 * 看提示了
 */
class Solution {
public:
    static bool myCmp(pair<int, bitset<26> > p1,pair<int, bitset<26> > p2 ){ return p1.first < p2.first;}

    int maxProduct(vector<string>& words) {
        int sz = words.size();
        if(sz == 0) return 0;
        vector<pair<int, bitset<26> > > w2s;
        for(int i = 0 ; i < sz; i ++){
            bitset<26> bs;
            for(char c : words[i])
                bs.set(c-'a');
            w2s.push_back(make_pair(words[i].length(),bs));
        }
        sort(w2s.begin(), w2s.end(), myCmp);
        int re = 0;
        for(int i = w2s.size()-1; i >= 0; i --)
            for(int j = i-1; j >= 0 ; j --){
                if(w2s[i].first * w2s[j].first <= re || (w2s[i].second & w2s[j].second).count() > 0) continue;
                re = re > w2s[i].first * w2s[j].first ? re : w2s[i].first * w2s[j].first;
            }
        return re;
    }
};
