/*
 * 计算反序数.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */


#include <stdio.h>
#include <string.h>
int main(){
	int k = 6;
	while(k--){
		char c[100];
		scanf("%s", c);
		int ei = 0;
		if(c[0] == '-'){
			if(strlen(c)> 1 && c[1] != '0')
				printf("-");
			ei = 1;
		}
		bool beg = true, out = false;
		for(int i = strlen(c)-1; i >= ei ; i--){
			if(beg && c[i] == '0')
				continue;
			else beg = false;
			printf("%c", c[i]);
			out = true;
		}
		if(!out)
			printf("0");
		printf("\n");
	}
	return 0;
}

