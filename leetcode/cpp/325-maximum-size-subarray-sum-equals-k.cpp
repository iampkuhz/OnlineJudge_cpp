/*
 *
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?

Show Company Tags
Show Tags
Show Similar Problems
*/
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * 看答案
 */
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sum2ind;
        int curSum = 0, maxLen = 0;
        for(int i = 0; i < nums.size(); i ++){
            curSum += nums[i];
            if(curSum == k) maxLen = i+1;
            else if(sum2ind.find(curSum-k) != sum2ind.end() && (i - sum2ind[curSum-k]) >  maxLen)
                maxLen = i - sum2ind[curSum-k];
            if(sum2ind.find(curSum) == sum2ind.end())
                sum2ind[curSum] = i;
        }
        return maxLen;
    }
};

/*
 * 2次过，速度超级慢
 */
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sz = nums.size();
        if(sz == 0) return 0;
        int *sum = new int[sz+1];
        sum[0] = 0;
        for(int i = 0 ;  i < sz; i ++)
            sum[i+1] = sum[i] + nums[i];
        for(int j = sz; j > 0; j --){
            for(int i = 0  ; i <= sz - j; i ++)
                if(sum[i+j] - sum[i] == k)
                    return j;
        }
        return 0;
    }
};
