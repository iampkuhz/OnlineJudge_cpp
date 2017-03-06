/*
 *Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> re;
        int sz = nums.size();
        if(sz == 0){
            if(lower == upper) re.push_back(to_string(lower));
            else re.push_back(to_string(lower) + "->" + to_string(upper));
            return re;
        }
        nums.push_back(upper+1);
        int missL = lower;
        for(int i = 0 ; i < sz+1; i ++){
            if(nums[i] == missL) missL ++;
            else{
                if(nums[i] == missL + 1) re.push_back(to_string(missL));
                else re.push_back(to_string(missL) + "->" + to_string(nums[i]-1));
                missL = nums[i] + 1;
            }
        }
        return re;

    }
};
