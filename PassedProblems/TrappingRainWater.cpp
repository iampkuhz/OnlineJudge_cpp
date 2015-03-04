/*
 * TrappingRainWater.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <stack>
using namespace std;
class Rect
{
public:
	int h;
	int w;
	Rect(int h1, int w1){
		h = h1;
		w = w1;
	}
};
class Solution {
public:
    int trap(int A[], int n) {
    	stack<Rect> boxes;
    	int capa = 0;
    	for(int i = 0 ; i < n; i ++)
    	{
    		Rect * newBox = new Rect(A[i], 1);
    		while(true){
    			if(boxes.empty() || boxes.top().h > newBox->h) {
    				boxes.push(*newBox);
    				break;
    			}
    			else{
    				Rect top = boxes.top();
    				boxes.pop();
    				if(boxes.empty()) continue;
    				else if(top.h == newBox->h){
    					newBox->w += top.w;
    					continue;
    				}
    				else{
    					Rect top2 = boxes.top();
    					if(top2.h < newBox->h){
    						capa += (top2.h - top.h) * top.w;
    						top2.w += top.w;
    						boxes.pop();
    						boxes.push(top2);
    					}
    					else {
    						capa += (newBox->h - top.h) * top.w;
    						newBox->w += top.w;
    					}
    				}
    			}
    		}

    	}
    	return capa;
    }

    void test()
    {
    	int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    	cout << trap(A, 12) << endl;
    }
};


