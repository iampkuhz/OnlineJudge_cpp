/*
 * O(n*k*k)复杂度，2次过，最后错误求成最大值了；
 * O(n*k)算法： 可以记录每个房间的最小值、次小值和他们的颜色（下标），如果下一行和最小值颜色相同，就用次小值的颜色，否则，都用最小值的颜色
 *
 *There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n < 1) return 0;
        int k = costs[0].size();
        vector<vector<int> > sum(n+1, vector<int>(k,0));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < k; j ++){
                int tmin = sum[i][0];
                if(j == 0) tmin = sum[i][1];
                for(int l = 0 ; l < k; l ++)
                    if(l != j && sum[i][l] < tmin)
                        tmin = sum[i][l];
                sum[i+1][j] = tmin + costs[i][j];
            }
        }
        int re = sum[n][0];
        for(int j = 1; j < k; j ++)
            re = re < sum[n][j] ? re : sum[n][j];
        return re;
    }
};
