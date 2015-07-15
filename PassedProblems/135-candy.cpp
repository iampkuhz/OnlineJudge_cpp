/*
 * 135-candy.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include <queue>
#include "memory.h"
using namespace std;

class Solution {
public:
	class intPair{
	public:
		int index;
		int cnt;
		intPair(int i, int c): index(i), cnt(c) {}
	};
    int candy(vector<int>& ratings) {
        queue<intPair> q;
        int size = ratings.size();
        int * cn = new int[size];
        bool * visit = new bool[size];
        memset(visit, false, sizeof(bool) * size);
        memset(cn, 0, sizeof(int) * size);

        for(int i = 0; i < size; i ++)
        {
        	if(!((i > 0 && ratings[i] > ratings[i-1]) ||
        			(i < size - 1 && ratings[i] > ratings[i+1])))
        	{
        		intPair * one = new intPair(i, 1);
        		q.push(*one);
        		visit[i] = true;
        		cn[i] = 1;
        	}
        }
        while(q.size() > 0)
        {
        	intPair fr = q.front();
        	q.pop();
        	int i = fr.index;
        	if(i > 0 && ratings[i-1] > ratings[i])
        	{
        		cn[i-1] = cn[i-1] < fr.cnt + 1 ? fr.cnt + 1 : cn[i-1];
        		if(visit[i-1] == false)
        		{
        			intPair * left = new intPair(i-1, cn[i-1]);
        			q.push(*left);
        			visit[i-1] = true;
        		}
        	}
        	if(i < size - 1 && ratings[i+1] > ratings[i])
        	{
        		cn[i+1] = cn[i+1] < fr.cnt + 1 ? fr.cnt + 1 : cn[i+1];
        		if(visit[i+1] == false)
        		{
        			intPair * right = new intPair(i+1, cn[i+1]);
        			q.push(* right);
        			visit[i+1] = true;
        		}
        	}
        }
        int sum = 0;
        for(int i = 0 ; i < size ; i ++)
        	sum += cn[i];
        return sum;
    }
};



