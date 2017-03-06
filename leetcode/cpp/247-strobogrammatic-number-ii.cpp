/*
 * 找到所有长度为n的Strobogrammatic数
 * 2次过，简单
 */


class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> vs, vs0 = {""}, vs1 = {"1","0", "8"};
        vector<vector<string> > p = {{"1","1"},{"8","8"},{"6","9"},{"9","6"},{"0","0"}};
        if(n <= 0) return vs;
        if(n % 2 == 0) vs = vs0;
        else vs = vs1;
        while(n > 1){
            n -= 2;
            vector<string> vsn;
            int szvs = vs.size();
            for(int i = 0; i < szvs; i ++){
                int psz = n > 1 ? 5:4;// 最后一次开头不能是0
                for(int j = 0 ; j < psz; j ++)
                    vsn.push_back(p[j][0] + vs[i] + p[j][1]);
            }
            vs = vsn;
        }
        return vs;
    }
};
