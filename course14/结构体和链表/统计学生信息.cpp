/*
 * 统计学生信息.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct info{
	char c[300];
	info * front;
};
int main(){
	info * front= NULL;
	while(true){
		info * t = (info*)malloc(sizeof(info));
		if(front != NULL)
			t->front = front;
		else t->front = NULL;
		gets(t->c);
		front = t;
		if(strcmp(t->c, "end") == 0){
			break;
		}
	}
	front = front->front;
	while(front != NULL){
		printf("%s\n", front->c);
		front = front->front;
	}
	return 0;
}


