/*
 * 不能一起吃的食物.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */
#include <stdio.h>
#include <string.h>
char * foodPairs [11][2] = {
  {"potato", "persimmon"},
  {"egg", "glucide"},
  {"onion", "honey"},
  {"bean-curd", "honey"},
  {"radish", "agaric"},
  {"taro", "banana"},
  {"pignut", "cucumber"},
  {"beef", "chestnut"},
  {"rabbit", "celery"},
  {"crab", "persimmon"},
  {"carp", "liquorice"}};

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		char a[65], b[65];
		scanf("%s %s", a,b);
		bool conf = false;
		for(int i = 0 ; i < 11; i++)
			if((strcmp(a, foodPairs[i][0])==0 && strcmp(b, foodPairs[i][1])==0)
				|| (strcmp(a, foodPairs[i][1])==0 && strcmp(b, foodPairs[i][0])==0)){
				conf = true;
				break;
			}
		if(conf)
			printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}


