/*
 * 计算鞍点.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: hanzhe
 */


#include <stdio.h>
int main(){
	int ss[7][7];
	int v;
	int r[7], c[7];
	for(int i = 1 ; i <= 5;i ++){
		r[i] = 1;
		for(int j = 1 ; j <= 5; j ++){
			scanf("%d", &v);
			ss[i][j] = v;
			if(v > ss[i][r[i]])
				r[i] = j;
		}
	}
	for(int j = 1; j <= 5; j ++)
	{
		c[j] = 1;
		for(int i = 2; i<=5; i ++)
			if(ss[i][j] < ss[c[j]][j])
				c[j] = i;
	}
	bool find = false;
	for(int i = 1; i <= 5; i ++)
		if(c[r[i]] == i){
			printf("%d %d %d\n", i, r[i], ss[i][r[i]]);
			find = true;
		}
	if(!find)
		printf("not found");
	return 0;
}

