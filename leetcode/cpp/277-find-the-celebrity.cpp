/*
 * 还有一种思路：遍历2遍：第一遍找可能的候选，第二遍检验候选；找候选如果i不认识候选，把候选替换成i
 * 2次过，速度还可以
 * 找到0-(n-1)中被其他所有人认识但是自己不认识任何人的人
 */

#include <vector>
using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(n <= 1) return n-1;
        vector<int> stat(n,0);// -1 有人不知道自己；-2 认识别人
        int ind = 0;
        while(ind < n){
            if(stat[ind] < 0) {
                ind ++;
                continue;
            }
            for(int i = 0; i < n; i ++){
                if(i == ind) continue;
                if(!knows(i, ind)){
                    stat[ind] = -1;
                    break;
                }
                else stat[i] = -2;
                if(knows(ind, i)){
                    stat[ind] = -2;
                    break;
                }
                else stat[i] = -1;
            }
            if(stat[ind] >= 0) return ind;
            ind ++;
        }
        return -1;
    }
};
