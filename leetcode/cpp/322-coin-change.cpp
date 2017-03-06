/*
 * 计算使用的最少硬币数
 * 数组记录+ dfs
 *Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.
 */



class Solution {
    vector<int> * cMin;
    vector<int> * co;
    int coLen;
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> t(1+amount, -2);
        cMin = &(t);
        co = &coins;
        coLen = coins.size();
        return getMin(amount);
    }
    int getMin(int n){
        if(n == 0) return 0;
        if(n < 0) return -1;
        if((*cMin)[n] > -2) return (*cMin)[n];
        int re = -1;
        for(int i = 0 ; i < coLen; i ++)
            if(n >= (*co)[i]){
                int cmin = getMin(n - (*co)[i]);
                if(cmin > -2)
                    re = re == -1 && cmin >= 0 ? cmin+1 : (cmin >= 0 ? min(re, cmin + 1) : re);
            }
        (*cMin)[n] = re;
        return re;
    }
};
