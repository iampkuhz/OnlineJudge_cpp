/*
 * 判断2个字符串的编辑距离是否是1
 */

/*
 * 看答案
 */
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int szs = s.length(), szt = t.length();
        if(abs(szs - szt) > 1) return false;
        for(int i = 0 ;i < min(szs, szt); i ++)
            if(s[i] != t[i]){
                return s.substr(i+1 - (szs < szt ? 1:0)) == t.substr(i+1 - (szt < szs ? 1:0));
            }
        return szs != szt;
    }
};


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int szs = s.length(), szt = t.length();
        if(abs(szs - szt) > 1) return false;
        if(szs > szt) return isOneEditDistance(t, s);
        if(szs == szt){
            int dif = 0;
            for(int i = 0 ; i < szs; i ++)
                if(s[i] != t[i]){
                    if((dif ++) > 1) return false;
                }
            return dif == 1;
        }else{
            int dif = 0;
            for(int i = 0; i < szt; i ++){
                if(t[i] != s[i+dif]){
                    if((dif--) < -1) return false;
                }
            }
            return dif == 0;
        }
    }
};
