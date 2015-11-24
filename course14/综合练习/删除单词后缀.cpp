/*
 * 删除单词后缀.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: hanzhe
 */

#include <stdio.h>
#include <string.h>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < n ;i ++){
		char word[100];
		scanf("%s", word);
		int len = strlen(word);
		if(len <= 2 || (len == 3 && strcmp(word, "ing") == 0))
			printf("%s\n", word);
		else{
			int g = len -2;
			if(word[len-1] == 'g')
				g = len - 3;
			for(int i = 0 ; i < g; i ++)
				printf("%c", word[i]);
			printf("\n");
		}
	}
}


