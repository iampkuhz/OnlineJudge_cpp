/*
 * 最长单词2.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: hanzhe
 */


#include <stdio.h>
int main(){
	char a[1000];
	int ind[1000];
	ind[0] = -1;
	gets(a);
//	printf("%s",a);
	int n = 1;
	for(int i = 0 ; i < 1000; i ++){
		if(a[i] == '\0')
			break;
		if(a[i] == ' ' || a[i] == '.'){
			ind[n] = i;
			n ++;
		}
	}
	int maxLen = 0;
	for(int i = 1; i < n; i ++)
		maxLen = (ind[i] - ind[i-1]>maxLen) ? (ind[i]-ind[i-1]):maxLen;
	for(int i = 1; i < n; i ++)
		if(ind[i] - ind[i-1] == maxLen){
			for(int j = ind[i-1] + 1; j < ind[i]; j ++)
				printf("%c",a[j]);
//			printf("\n");
			break;
		}
	return 0;
}

