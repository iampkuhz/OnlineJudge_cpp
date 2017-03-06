/*
 * 动规，简单
 */
#include <vector>
using namespace std;

/*
 * 3次过，min函数写错、递推式里的0写成1了
 */
class Solution {
public:
    int minCost(vector<vector<int> >& costs) {
        int sz = costs.size();
        if(sz < 1) return 0;
        vector<vector<int> > minc(sz+1, vector<int>(3,0));
        for(int i = 0 ; i < sz; i ++){
            minc[i+1][0] = min(minc[i][1], minc[i][2]) + costs[i][0];
            minc[i+1][1] = min(minc[i][0], minc[i][2]) + costs[i][1];
            minc[i+1][2] = min(minc[i][1], minc[i][0]) + costs[i][2];
        }
        return min(minc[sz][0], min(minc[sz][1], minc[sz][2]));
    }
    //int min(int a, int b){ return a if a < b else b;}
};
