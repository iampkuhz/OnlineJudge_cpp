/*
 * 223-rectangle-area.cpp
 *
 *  Created on: Sep 23, 2015
 *      Author: hanzhe
 */

#include <cmath>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = getSize(A,B,C,D) , s2 = getSize(E,F,G,H);
        int h = getOver(A,C,E,G), l = getOver(B,D,F,H);
        return s1 + s2 - h * l;
    }
    int getOver(int a, int c, int e, int g){
    	if(a > c) return getOver(c, a, e, g);
    	if(e > g) return getOver(a, c, g, e);
    	int mi = a < e ? e : a, ma = c < g ? c : g;
    	return mi < ma ? (ma - mi) : 0;
    }
    int getSize(int a, int b, int c, int d){
    	return abs(a-c) * abs(b-d);
    }
};

