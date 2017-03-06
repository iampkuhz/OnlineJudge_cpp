/*
 * 看答案，1次过
 *Given s = "the sky is blue",
return "blue is sky the".
*/


class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int sz = s.length();
        int st = 0;
        for(int i = 0 ; i < sz; i ++){
            if(s[i] == ' '){
                reverse(s.begin() + st, s.begin() + i);
                st = i+1;
            }
        }
        reverse(s.begin() + st, s.end());

    }
};
