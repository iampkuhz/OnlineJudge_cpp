/*
 * 找2个下标，使得和为target
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> re;
        vector<pair<int,int> > ns;
        for(int i = 0 ; i < nums.size(); i ++)
            ns.push_back(make_pair(nums[i], i));
        sort(ns.begin(),ns.end());
        int l = 0, r = nums.size()-1;
        while(l < r){
            int sum = ns[l].first + ns[r].first;
            if(sum == target){
                int ia = ns[l].second, ib = ns[r].second;
                re.push_back(ia);
                re.push_back(ib);
                return re;
            }
            else if(sum > target) r --;
            else l ++;
        }
    }
};
