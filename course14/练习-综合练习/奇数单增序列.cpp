/*
 * 奇数单增序列.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */


#include <stdio.h>
int main(){
	int k;
	scanf("%d", &k);
	int a[600], an = 0;;
	for(int i = 0 ; i < k; i++){
		int t;
		scanf("%d", &t);
		if(t% 2 == 1)
			a[an++] = t;
	}
	//冒泡排序
	for(int i = an-1; i>=0; i --)
		for(int j = 0 ;j < i; j ++)
			if(a[j] > a[j+1]){
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
	printf("%d", a[0]);
	for(int i = 1 ;i < an ; i ++)
		printf(",%d", a[i]);
	return 0;
}

