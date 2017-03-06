/*
 * string-to-integer-atoi/
 */

class Solution {
    bool myL(string &a, string &b){
        int la = a.length(), lb = b.length();
        if(la != lb) return la > lb;
        for(int i = 0 ; i < la ; i ++){
            if( a[i] != b[i])
                return a[i] > b[i];
        }
        return false;
    }
public:
    int myAtoi(string str) {
        while(str.length() > 0 && str[0] == ' ') str = str.substr(1);
        for(int i = 0 ; i < str.length(); i ++)
            if((str[i] < '0'||str[i] >'9')){
                if(i == 0 && (str[i] == '-' || str[i] == '+'))
                    continue;
                str = str.substr(0,i);
                break;
            }
        int sz = str.length();
        if(sz == 0) return 0;
        string mnt(to_string(INT_MIN));
        if(str == mnt)
            return INT_MIN;
        mnt = mnt.substr(0);
        string mxt(to_string(INT_MAX));

        bool neg = (str[0] == '-');
        if(neg || str[0] == '+') str = str.substr(1);
        if(myL(str, mxt)) return neg? INT_MIN:INT_MAX;
        if(str.length() < 1) return 0;
        int re = 0;
        for(int i = 0; i < str.length(); i ++){
            if(str[i] < '0' || str[i] > '9') return neg? -re:re;
            re = re*10 + str[i] - '0';
        }
        if(neg)  re = -re;
        return re;
    }
};
