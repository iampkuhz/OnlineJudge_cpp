/*
 * 问一个数字颠倒180度是不是还是本身，0,1,8,6(9）这几个的组合
 */

class Solution {
public:
    int char2int(char c){
        if(c >= '0' && c <= '9')
        {
            switch (c-'a'){
                case 0: return 0;break;
                case 1: return 1;break;
                case 8: return 2;break;
                case 6: return 3;break;
                case 9: return 4;break;
            }
        }
        return -1;
    }
    bool isStrobogrammatic(string num) {
        int sz = num.length();
        for(int i = 0 ; i <= sz/2; i ++){
            int v1 = char2int(num[i]), v2 = char2int(num[sz-i-1]);
            if(!(v1 >= 0 && v2 >= 0 && ((v1 == v2 && v1 < 3) || (v1+v2==7))))
                return false;
        }
        return true;
    }
};

