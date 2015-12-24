/*
 * 班级学生成绩统分.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */


#include <stdio.h>
#include <stdlib.h>
struct stu{
	int id;
	int sum;
	stu * next;
};
struct top3{
	stu * a;
	stu * b;
	stu * c;
};
void myAdd(top3 * re, stu * t){
	if(re->a == NULL || re->a->sum < t->sum){
		re->c = re->b; re->b = re->a;
		re->a = t;
	}
	else if(re->b == NULL || re->b->sum < t->sum){
		re->c = re->b; re->b = t;
	}
	else if(re->c == NULL || re->c->sum < t->sum)
		re->c = t;
}
int main(){
	int k;
	scanf("%d", &k);
	stu * pre=NULL, * head = NULL;
	top3 *re = (top3*)malloc(sizeof(top3));
	re->a = re->b = re->c = NULL;
	while(k--){
		stu * t = (stu*)malloc(sizeof(stu));
		int sa, sb;
		scanf("%d %d %d", &t->id, &sa, &sb);
		t->sum = sa + sb;
		myAdd(re, t);
	}
	printf("%d %d\n", re->a->id, re->a->sum);
	printf("%d %d\n", re->b->id, re->b->sum);
	printf("%d %d\n", re->c->id, re->c->sum);
}

