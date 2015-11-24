/*
 * 判断字符串是否为回文.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: hanzhe
 */




#include <stdio.h>
#include <string.h>

int main(){
	char a[150];
	scanf("%s", a);
	int len = strlen(a);
	bool re = true;
	for(int i = 0 ; i < len/2; i ++)
		if(a[i] != a[len-1-i]){
			re = false;
			break;
		}
	if(re)
		printf("yes");
	else printf("no");
	return 0;
}
