/*
 * 全排列.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: hanzhe
 */



#include <stdio.h>

int r[10] = {0,1,2,3,4,5,6,7,8,9};
int len;
void mreverse(int a, int b){
//	printf("rev %d %d\n", a, b);
	int t = r[a];
	r[a] = r[b];
	r[b] = t;
}
int getNext(){
	int i;
	for(i = len - 1; i >= 0; i --)
		if(r[i] < r[i+1])
			break;
	if(i >= 0){
		int j;
		for(j = len; j > i; j --)
			if(r[j] > r[i])
				break;
		mreverse(i, j);
		for(int k = i + 1; k <= (len - i)/2 + i; k ++)
			mreverse(k, len + i + 1 -k);
//		printf("%d %d\n", i, j);
	}
//	for(int k = 0 ; k <= len; k ++)
//		printf("%d ", r[k]);
//	printf("c\n");
	return i;
}
int main(){
	char a[10];
	scanf("%s", a);
	for(int i = 0 ; i < 10; i ++)
		if(a[i] == '\0'){
			len = i - 1;
			break;
		}
	while(true){
		for(int i = 0 ; i <= len ; i ++)
			printf("%c", a[r[i]]);
		printf("\n");
		int bInd = getNext();
		if(bInd < 0)
			break;
	}
	return 0;
}
