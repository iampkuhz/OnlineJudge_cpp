/*
 * 进制转换.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */
#include <stdio.h>
int main(){
	int k;
	scanf("%d", &k);
	while(k--){
		char s[100];
		scanf("%s", s);
		int re = 0;
		for(int i = 0 ; s[i] != '\0' ; i ++){
			int ad = s[i] >= 'A' ? s[i]-'A'+10 : s[i] - '0';
			re = re * 14 + ad;
		}
		char c[200];
		int cl = 0;
		while(re > 0){
			c[cl++] = re % 7 + '0';
			re /= 7;
		}
		for(int i = cl-1; i >=0 ;i --)
			printf("%c", c[i]);
		if( cl == 0)
			printf("0");
		if(k > 0)
			printf(" ");
	}
//	printf("%d %d %d", 'a', '0', 'A');
}


