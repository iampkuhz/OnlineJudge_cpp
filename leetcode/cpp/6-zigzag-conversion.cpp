/*
 * 将字符串按锯齿从上往下、再往右上排列，再按行从上往下读出来
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> ss(numRows,"");
        for(int i = 0 ; i < s.length(); i ++){
            int l = i % (2*numRows-2);
            l = l > numRows-1 ? 2*(numRows-1)-l:l;
            ss[l] += s[i];
        }
        string re = "";
        for(string ts:ss)
            re += ts;
        return re;
    }
};

