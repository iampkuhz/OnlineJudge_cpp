/*
 * 计概助教课做过，2次过（第一次忘记去掉本身了）
 * 求n的所有因式分解的结果，从小到大牌
 */

#include <vector>
#include <math.h>

using namespace std;

class Solution {
    vector<vector<int>> re;

public:
    vector<vector<int>> getFactors(int n) {
        vector<int> list;
        getVec(n, 2, list);
        return re;
    }

    void getVec(int n, int minBound, vector<int> & list){
        if(n >= minBound && list.size() > 0){
            list.push_back(n);
            re.push_back(list);
            list.pop_back();
        }

        if(n < minBound) return;
        int sn = sqrt(n);
        for(int i = minBound; i <= sn; i ++)
            if(n % i == 0){
                list.push_back(i);
                getVec(n/i, i, list);
                list.pop_back();
            }
    }
};
