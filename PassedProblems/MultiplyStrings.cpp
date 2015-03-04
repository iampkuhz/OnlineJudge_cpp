/*
 * MultiplyStrings.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        string multi = num2;
        std::reverse(multi.begin(), multi.end());
        std::reverse(num1.begin(), num1.end());
        //cout << "multi:" << multi << endl;
        string result;
        string zeroes = "";
        for(int i = 0 ; i < num1.length(); i ++)
        {
        	string adder = zeroes + SingleMul(multi, num1[i]-'0');
        	result = myAdd(result, adder);
        	zeroes += "0";
        	//cout << num2[i] << " adder:" << adder << " re:" << result << endl;
        }
        std::reverse(result.begin(), result.end());
        while(result.length() > 1 && result[0] == '0')
        	result = result.substr(1 );
        return result;
    }

    stringstream ss;
    string SingleMul(string base, int times)
    {
    	string result = "";
    	int carry = 0;
    	for(int i = 0 ; i < base.length(); i ++)
    	{
    		int sum = (base[i] - '0') * times + carry;
    		char c = '0' + (sum % 10);
    		result += c;
    		carry = sum / 10;
    	}
    	if(carry > 0){
    		char c = '0' + carry;
    		result += c;
    	}
    	return result;
    }

    string myAdd(string base, string adder)
    {
    	//cout << adder << " " << base << endl;
    	//adder = "0" + adder;
    	//cout << adder << " " << base << endl;
    	int len = base.length() > adder.length() ? base.length() : adder.length();
    	while(base.length() < len)
    		base = base + "0";
    	while(adder.length() < len)
    		adder += "0";
    	//cout << adder << " " << base << endl;
    	string result = "";
    	int carry = 0;
    	for(int i = 0 ; i < len; i ++)
    	{
    		int sum = carry + (base[i] - '0') + (adder[i] - '0');
    		char  c = '0' + (sum % 10);
    		result += c;
    		carry = sum /10;
    	}
    	if(carry > 0 ){
    		char c = '0' + carry;
    		result += c;
    	}
    	return result;
    }

    void test(){
    	string s1 = "123", s2 = "23";
    	cout << multiply(s1, s2) << endl;
    	cout << multiply(s1, "0") << endl;
    }
};



