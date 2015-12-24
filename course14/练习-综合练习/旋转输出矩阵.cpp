/*
 * 旋转输出矩阵.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */

#include <stdio.h>

int k;
int a[130][130];
bool v[130][130];
int l[10100];
int ln;
void fillL(int x, int y, int dx, int dy){
//	printf("%d %d %d %d\n", x, y, dx, dy);
	if(ln >= k*k)
		return;
	int nx = x+dx, ny = y+dy;
	if(nx >=0 && nx < k && ny >=0 && ny <k && v[nx][ny] == false){
		v[nx][ny] = true;
		l[ln++] = a[nx][ny];
		fillL(nx, ny, dx, dy);
	}
	else{
		//(0,1)->(1,0)->(0,-1)->(-1,0)->(0,1)
		int ody = dy;
		dy = dy == 0 ? dy-dx: 0;
		dx = ody;
		fillL(x, y, dx, dy);
	}
}
int main(){
	// 1. 矩阵->数组
	scanf("%d", &k);
	for(int i =  0 ;i  < k ; i ++)
		for(int j = 0 ;j < k ; j ++)
			scanf("%d", &a[i][j]);
	ln = 0;
	l[ln++] = a[0][0];
	v[0][0] = true;
	fillL(0,0, 0, 1);
	// 2. 数据->头尾两个指针输出
	printf("%d", l[0]);
	int pl = 1, pr = k*k-1;
	while (pl < pr){
		printf(" %d %d", l[pr], l[pl]);
		pl ++; pr --;
	}
	if (pl == pr)
		printf(" %d", l[pl]);
}


