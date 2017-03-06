/*
 *
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

*/

#include <vector>
#include <algorithm>
using namespace std;


/*
 * 看答案，1次过
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int j = tmp.size()-1;
        for(int i = 1; i < tmp.size(); i+=2, j--) nums[i] = tmp[j];
        for(int i = 0; i < tmp.size(); i+=2, j--) nums[i] = tmp[j];
    }
};
