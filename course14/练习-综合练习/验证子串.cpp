/*
 * 验证子串.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */


#include <string.h>
#include <stdio.h>
int main(){
	char c[500], s2[500];
	scanf("%s %s", s2, c);
	if(strstr(s2,c) != NULL)
		printf("%s is substring of %s", c, s2);
	else if(strstr(c,s2) != NULL)
		printf("%s is substring of %s", s2, c);
	else printf("No substring");
	return 0;
}

