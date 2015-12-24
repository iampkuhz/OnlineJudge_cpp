/*
 * 文字排版.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */

#include <stdio.h>
#include <string.h>
int main(){
	int k;
	scanf("%d", &k);
	char w[500][50];
	for(int i = 0 ; i < k; i ++)
		scanf("%s", w[i]);
	int lineLen = strlen(w[0]);
	printf("%s", w[0]);
	for(int i = 1 ; i < k; i ++){
		int lenw = strlen(w[i]);
		if(lenw + 1 + lineLen > 80){
			printf("\n%s", w[i]);
			lineLen = lenw;
		}
		else {
			lineLen += 1 + lenw;
			printf(" %s", w[i]);
		}
	}
	return 0;
}


