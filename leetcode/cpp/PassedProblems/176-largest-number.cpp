/*
 * 176-largest-number.cpp
 *
 *  Created on: Aug 9, 2015
 *      Author: hanzhe
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
	static bool compare(string s1, string s2){
		if(s1 == "") return false;
		int len1 = s1.length(), len2 = s2.length();
		int i = 0;
		while(i < len1 && i < len2){
			if(s1[i] == s2[i])
				i ++;
			else if(s1[i] < s2[i])
				return false;
			else return true;
		}
		if(len1 == len2) return false;
		if(i < len1)
			return compare(s1.substr(i), s2);
		return !compare(s2.substr(i), s1);
	}
    string largestNumber(vector<int>& nums) {
        vector<string> nss;
        for(int i = 0 ; i < nums.size(); i ++)
        {
        	ostringstream os;
        	os << nums[i];
        	nss.push_back(os.str());
        }
        sort(nss.begin(), nss.end(), compare);
        string re = "";
        for(int i = 0 ; i < nss.size(); i ++)
        {
//        	cout << nss[i] << endl;
        	re += nss[i];
        }
        while(re.length() > 1 && re[0] == '0')
        	re = re.substr(1);
        return re;
    }

    void test(){
//    	int a[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//    	vector<int> ia(a,a+100);
    	int a[]={1,2};
    	vector<int> ia(a,a+2);
    	cout << largestNumber(ia) << endl;
    }
};
