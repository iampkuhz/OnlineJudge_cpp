/*
 * LongestValidParentheses.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <stack>
using namespace std;

class myPair{
public:
	bool start;
	int index;

	myPair(int i, bool b ){
		index = i;
		start = b;
	}
};

class brackPair{
public:
	int sInd;
	int eInd;

	brackPair(int s, int e){
		sInd = s;
		eInd = e;
	}
};
class Solution {
public:
    int longestValidParentheses(string s) {
    	stack<myPair> st;
    	stack<brackPair> bST;
    	int re = 0;
    	int max = 0;
    	for(int i = 0 ;i < s.length(); i ++){
    		bool sign = (s[i] == '(') ? true : false;
			myPair* one = new myPair(i, sign);
			//cout << i << " " << one->start  ;

    		if(sign == true){
    			st.push(*one);
    			//cout << " t " << st.top().start <<  endl;
    		}
    		else {
    			if(st.empty() == false && st.top().start == true){
        			//cout << " t2" << endl;
    				brackPair * bp = new brackPair(st.top().index, i);
    				//cout << "S:" << st.top().index << " " << i << endl;
    				while(bST.empty() == false && bST.top().sInd > (*bp).sInd)
    				{
    					//cout << "frop L:" << bST.top().eInd << " " << bST.top().sInd << endl;
    					bST.pop();
    				}
    				bST.push(*bp);
    				st.pop();
    			}
    			else{
        			//cout << " t4 " << st.empty()<< " " << st.top().start<< endl;
    				st.push(* one);
    			}
    		}
    	}

    	if(bST.empty())
    		return 0 ;
    	brackPair lst = bST.top();
    	bST.pop();
    	while(bST.empty() == false)
    	{
    		brackPair o = bST.top();
    		bST.pop();
    		if(o.eInd == lst.sInd - 1){
    			lst.sInd = o.sInd;
    		}
    		else{
    			re = lst.eInd - lst.sInd + 1;
    			//cout << lst.eInd << " " << lst.sInd << endl;
    			max = max > re ? max : re;
    			lst = o;
    		}
    	}
    	re = lst.eInd - lst.sInd + 1;
		//cout << lst.eInd << " " << lst.sInd << endl;
    	max = max > re ? max : re;
    	return max;
    }

    void test(){
    	for(int i = 0 ; i < 5; i ++ ){
    		string c;
    		cin >> c;
    		cout << longestValidParentheses(c) << endl;
    	}

    }
};



