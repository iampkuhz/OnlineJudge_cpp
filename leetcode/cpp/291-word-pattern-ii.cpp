/*
 * 2次过，时间速度可以，忘记c2s没有情况中最后的`return false`
 *Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
*/

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<string, char> s2c;
    unordered_map<char, string> c2s;
    int szp, szs;
    string p,s;
public:
    bool wordPatternMatch(string pattern, string str) {
        szp = pattern.length();
        szs = str.length();
        p = pattern;
        s = str;
        if(szp > szs) return false;
        return match(0,0);
    }
    bool match(int indp, int inds){
        if(indp >= szp || inds >= szs)
            return indp == szp && inds == szs;
        if((szp - indp) > (szs - inds))// 剪枝
            return false;
        if(c2s.find(p[indp]) == c2s.end()){// c2s 没有 p[indp], 需要新建一个
            for(int j = inds; j < szs; j ++){
                string ss(s, inds, j-inds+1);
                if(s2c.find(ss) == s2c.end()){
                    s2c[ss] = p[indp];
                    c2s[p[indp]] = ss;
                    if(match(indp+1, 1+j)) return true;
                    s2c.erase(ss);
                    c2s.erase(p[indp]);
                }
            }
            return false;
        }else{
            string ss = c2s[p[indp]];
            for(int i = 0 ; i < ss.length(); i ++)
                if(ss[i] != s[inds+i])
                    return false;
            return match(indp+1, inds+ss.length());
        }
    }
};
