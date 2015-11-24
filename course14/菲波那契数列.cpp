/*
 * 菲波那契数列.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: hanzhe
 */




#include <stdio.h>

int main(){
	int n;
	int a[30]={1,1};
	for(int i = 2 ; i < 25; i ++)
		a[i] = a[i-1] + a[i-2];
	scanf("%d", &n);
	for(int i = 0 ;i < n; i ++)
	{
		int b;
		scanf("%d", &b);
		printf("%d\n", a[b-1]);
	}
	return 0;
}
