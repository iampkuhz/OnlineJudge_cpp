/*
 * 生日相同.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: hanzhe
 */


#include <stdio.h>

int main(){
	int n;
	char num[200][12];
	int myId[13][32][102];
	int cntmy[13][32];
	for(int i = 0 ; i < 13; i ++)
		for(int j = 0 ;j < 32; j ++)
			cntmy[i][j] = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
	{
		int y,m;
		scanf("%s", num[i+1]);
		scanf("%d", &m);
		scanf("%d", &y);
		myId[m][y][cntmy[m][y]] = i+1;
		cntmy[m][y] ++;
	}
	for(int i = 1; i < 13; i ++)
		for(int j =1; j < 32; j ++)
			if(cntmy[i][j] > 1){
				printf("%d %d", i, j);
				for(int k = 0; k < cntmy[i][j]; k ++)
					printf(" %s", num[myId[i][j][k]]);
				printf("\n");
			}
	return 0;
}

