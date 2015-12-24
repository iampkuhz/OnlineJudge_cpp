/*
 * 谁拿了最多奖学金.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */

#include <stdio.h>
#include <stdlib.h>
struct stu{
	char name[100];
	int score;
	int repute;
	char qg;
	char west;
	int thesis;
	stu * next;
};
int getRes(stu * t){
	int re = 0;
	re += (t->score >80 && t->thesis >=1) ? 8000:0;
	re += (t->score >85 && t->repute >80) ? 4000:0;
	re += (t->score >90) ? 2000:0;
	re += (t->score >85 && t->west == 'Y') ? 1000:0;
	re += (t->repute >80 && t->qg == 'Y') ? 850:0;
	return re;
}
int main(){
	int k;
	scanf("%d", &k);
	stu *pre, * head=NULL, *max;
	int sum = 0;
	while(k --){
		stu * t = (stu*)malloc(sizeof(stu));
		scanf("%s %d %d %c %c %d", t->name, &(t->score), &(t->repute), &t->qg, &t->west, &t->thesis);
		if(head == NULL){
			head = pre = t;
			max = t;
		}
		else {
			pre->next = t;
			if(getRes(t) > getRes(max))
				max = t;
		}
		sum += getRes(t);
		t->next = NULL;
	}
	printf("%s\n%d\n%d", max->name, getRes(max), sum);
	return 0;
}

