/**
 * 在2个排序的数组中找中位数|
 */

class Solution {
    int sz1, sz2;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        sz1 = nums1.size(), sz2 = nums2.size();
        int am1 = findK((sz1+sz2+1)/2, nums1, nums2);
        int am2 = findK((sz1+sz2)/2+1, nums1, nums2);
        return (0.0+am1+am2)/2;
    }
    int findK(int k, vector<int>& n1, vector<int>& n2){
        int a1 = 0, b1 = sz1-1;
        int a2 = 0, b2 = sz2-1;
        while(k >= 0){
            if(a1 > b1) return n2[a2+k-1];
            if(a2 > b2) return n1[a1+k-1];

            int m1 = (b1+a1)/2;
            if(m1-a1+1>=k){
                if(m1 - a1 + 1 == k && n1[m1] <= n2[a2])
                    return n1[m1];
                b1 = m1-1;continue;
            }
            int m2 = k-(m1-a1+1)+a2-1;
            if(m2 > b2){
                k -= m1-a1+1;
                a1 = m1 +1;
                continue;
            }
            if(n1[m1] > n2[m2]){
                b1 = m1;
                k -= m2-a2+1;
                a2 = m2+1;
            }
            else{
                k -= m1-a1+1;
                a1 = m1+1;
                b2 = m2;
            }

        }
    }
};
