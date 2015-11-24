/*
 * 统计字符数.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: hanzhe
 */




#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	char a[1200];
	gets(a);
	for(int k = 0 ; k < n ; k ++){
		gets(a);
//		printf("a:%s\n", a);
		int cnt[50];
		for(int i = 0 ; i < 50; i ++)
			cnt[i] = 0;
		for(int i = 0 ; a[i] != '\0'; i ++)
			cnt[a[i]-'a'] ++;
		int mi = 0, m = 0;
		for(int i = 0 ; i < 50; i ++)
			if(cnt[i] > m){
				mi = i;
				m = cnt[i];
			}
		gets(a);
		printf("%c %d\n", mi + 'a', m);
	}
}
