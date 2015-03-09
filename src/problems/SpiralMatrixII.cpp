/*
 * SpiralMatrixII.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > re;
    int c, r;
    bool **p;
    int dx[4];
    int dy[4] ;
    vector<vector<int> > generateMatrix(int n) {
    	re.clear();
    	if(n == 0) return re;
    	vector<int> line;
    	for(int i = 0 ; i < n; i ++)
    		line.push_back(0);
    	for(int i = 0 ; i < n ; i ++)
    		re.push_back(line);

    	c = r = n;
        dx[0] = dx[2] = 0; dx[1] = 1; dx[3] = -1;
        dy[1] = dy[3] = 0; dy[0] = 1; dy[2] = -1;
        p = new bool *[r];
        for(int i = 0 ; i < r; i ++)
        {
        	p[i] = new bool[c];
        	for(int j = 0 ; j < c; j ++)
        		p[i][j] = false;
        }
        p[0][0] = true;
        re[0][0] = 1;
        //cout << "label" << c <<  " " << r <<endl;
        Step(2, 0, 0, 0, re);
        return re;
    }

    void Step(int sn, int dir, int x, int y, vector<vector<int> > &matrix)
    {
    	if(sn > c * r) return;
    	int nx = dx[dir] + x;
    	int ny = dy[dir] + y;
		//cout << x << " " << y << "; " << nx << " " << ny << " dir:" << dir << endl;;
    	if(nx < 0 || nx >= r || ny < 0 || ny >= c || p[nx][ny]){
    		Step(sn, (dir + 1)%4, x, y, matrix);
    		return;
    	}
    	else{
    		p[nx][ny] = true;
    		re[nx][ny] = sn;
    		Step(sn + 1, dir, nx, ny, matrix);
    		return;
    	}
    }

    void test()
    {
    	vector<vector<int> > re1 = generateMatrix(3);
    	for(int i = 0 ; i < re1.size(); i ++)
    	{
    		for(int j = 0 ; j < re1[i].size(); j ++)
    			cout << re1[i][j] << " ";
    		cout << endl;
    	}
    	vector<vector<int> > re2 = generateMatrix(5);
    	for(int i = 0 ; i < re2.size(); i ++)
    	{
    		for(int j = 0 ; j < re2[i].size(); j ++)
    			cout << re2[i][j] << " ";
    		cout << endl;
    	}
    }
};



