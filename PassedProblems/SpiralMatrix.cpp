/*
 * SpiralMatrix.cpp
 *
 *  Created on: 2015年3月7日
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> re;
    int c, r;
    bool **p;
    int dx[4];
    int dy[4] ;
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
    	if(matrix.size() < 1) return re;
        r = matrix.size();
        dx[0] = dx[2] = 0; dx[1] = 1; dx[3] = -1;
        dy[1] = dy[3] = 0; dy[0] = 1; dy[2] = -1;
        c = matrix[0].size();
        p = new bool *[r];
        for(int i = 0 ; i < r; i ++)
        {
        	p[i] = new bool[c];
        	for(int j = 0 ; j < c; j ++)
        		p[i][j] = false;
        }
        re.push_back(matrix[0][0]);
        p[0][0] = true;
        //cout << "label" << c <<  " " << r <<endl;
        Step(1, 0, 0, 0, matrix);
        return re;
    }

    void Step(int sn, int dir, int x, int y, vector<vector<int> > &matrix)
    {
    	if(sn >= c * r) return;
    	int nx = dx[dir] + x;
    	int ny = dy[dir] + y;
		//cout << x << " " << y << "; " << nx << " " << ny << " dir:" << dir << endl;;
    	if(nx < 0 || nx >= r || ny < 0 || ny >= c || p[nx][ny]){
    		Step(sn, (dir + 1)%4, x, y, matrix);
    		return;
    	}
    	else{
    		p[nx][ny] = true;
    		re.push_back(matrix[nx][ny]);
    		Step(sn + 1, dir, nx, ny, matrix);
    		return;
    	}
    }

    void test()
    {
    	vector<vector<int> > inp;
    	int va[] = {1,2,3};
    	int vb[] = {4,5,6};
    	int vc[] = {7,8,9};
    	vector<int> v(va, va+3);
    	vector<int> b(vb, vb+3);
    	vector<int> c(vc, vc+3);
    	inp.push_back(v);
    	inp.push_back(b);
    	inp.push_back(c);
    	vector<int> re = spiralOrder(inp);
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << re[i] << " ";
    }
};


