/*
 *Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].

*/

#include <vector>
#include <algorithm>
using namespace std;

/*
 * 看答案,2次过,O(nlogn)
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 2; i < sz; i += 2)
            swap(nums[i], nums[i-1]);
    }
};

/*
 * 看答案,2次过,O(n)
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return;
        for(int i = 1; i < sz; i ++)
            if(((i&1) && nums[i] < nums[i-1]) || (!(i&1) && nums[i] > nums[i-1]))
                swap(nums[i], nums[i-1]);
    }
};
