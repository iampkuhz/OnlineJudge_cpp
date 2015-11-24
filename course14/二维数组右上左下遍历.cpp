/*
 * 二维数组右上左下遍历.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: hanzhe
 */

#include <stdio.h>

int main(){
	int ss[101][101];
	int c,r;
	int v;
	scanf("%d %d", &r, &c);
	for(int i = 0 ; i < r; i ++)
		for(int j = 0; j < c; j ++){
			scanf("%d", &v);
			ss[i][j] = v;
		}
	for(int i = 0 ; i < c+r - 1; i ++){
		int j = i;
		if(j >= c)
			j = c-1;
		int k = i - j;
		while(k < r && j >= 0){
			printf("%d\n", ss[k][j]);
			k ++;
			j --;
		}
	}
	return 0;
}


