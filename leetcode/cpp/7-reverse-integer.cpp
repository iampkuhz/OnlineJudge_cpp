/*
 * 颠倒数字
Example1: x = 123, return 321
Example2: x = -123, return -321

 */


class Solution {
public:
    bool myLE(string &a, string &b){
        if(a.length() != b.length()) return a.length() < b.length();
        for(int i = 0  ; i < a.length(); i ++)
            if(a[i]!= b[i])
                return a[i] < b[i];
        return true;
    }
    int reverse(int x) {
        bool neg = x < 0;
        if(neg) x = -x;
        string t(to_string(x));
        std::reverse(t.begin(), t.end());
        string mxt(to_string(INT_MAX));
        if(myLE(mxt, t)) return 0;
        int re = stoi(t);
        if(neg) re = -re;
        return re;
    }
};
