/*
 *Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?

*/

#include <vector>
#include <algorithm>
using namespace std;

/*
 * 看到答案，9次过
 */
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        if(sz < 3) return 0;
        int cnt = 0;
        for(int i = 0; i < sz - 2; i ++){
            int j = i+1, k = sz - 1;
            int ttar = target - nums[i];
            while(j < k){
                while(k > j && nums[j] + nums[k] >= ttar) k--;
                cnt += k-j;
                j ++;
            }
        }
        return cnt;

    }
};
