/*
 * 二维数组中的最大数.cpp
 *
 *  Created on: Nov 23, 2015
 *      Author: hanzhe
 */

#include <stdio.h>

int main(){
	int a[12];
	for(int i = 0 ; i < 12; i ++)
		scanf("%d", &a[i]);
	int * p = &a[0];
	int mx = a[0], mIn = 0, mAd = 2000;
	while(p <= &a[11]){
		if(*p > mx){
			mx = *p;
			mIn = p - &a[0];
			mAd = 2000 + mIn * 4;
		}
		p+=1;
	}
	printf("%d %d\n%d", mx, (mIn+1), mAd);
	return 0;
}


