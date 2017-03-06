/*
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

/*
 * 看答案，O(nk）时间复杂度，O(k)空间复杂度：https://leetcode.com/discuss/32338/share-my-c-dp-solution-with-o-kn-time-o-k-space-10ms
 * hold[j] j次交易已买入时的最大收益
 * sale[j] j次交易已卖出时的最大收益
 * hold[j] = max(hold[j],sale[j-1] - prices[i])
 * sale[j] = max(sale[j],hole[j] + prices[i])
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        if(k>= n/2){
            int re = 0;
            for(int i = 1; i < n; i ++)
                re += max(0, prices[i] - prices[i-1]);
            return re;
        }
        vector<int> sale(k+1,0);
        vector<int> hold(k+1,INT_MIN);
        for(int i = 0 ; i < n; i ++){
            int c = prices[i];
            for(int j = 1; j <= k; j ++){
                sale[j] = max(sale[j], hold[j] + c);
                hold[j] = max(hold[j], sale[j-1] -c);
            }
        }
        return sale[k];
    }
};


/*
 * O(n^2*k)复杂度
 * O(n*k)空间复杂度
 * Runtime Error!!!
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > re(n+1, vector<int>(k+1,0));
        for(int i = 0 ; i < n; i ++){
            for(int l = 0; l < k +1; l ++)
                re[i+1][l] = re[i][l];
            for(int j = 0; j < i ; j ++)
                if(prices[j] < prices[i]){
                    int prof = prices[i] - prices[j];
                    for(int l = 0 ; l < k; l ++)
                        re[i+1][l+1] = max(re[i+1][l+1], re[j][l] + prof);
                }
        }
        int mx = 0;
        for(int j = 0 ; j <= k; j ++)
            mx = max(mx, re[n][j]);
        return mx;
    }
};
