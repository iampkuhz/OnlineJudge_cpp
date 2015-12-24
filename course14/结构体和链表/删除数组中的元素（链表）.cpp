/*
 * 删除数组中的元素（链表）.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int v;
	node * next;
};
int main(){
	int k;
	scanf("%d", &k);
	node *head=NULL, *t, * pre=NULL; //pre =NULL 就过了
	while(k--){
		t = (node*)malloc(sizeof(node));
		if(pre == NULL){
			head = t;
			pre = t;
		}
		else pre->next = t;
		scanf("%d", &(t->v));
		pre = t;
	}
	t->next = NULL;
	int dv;
	scanf("%d", &dv);
	while(head != NULL && head->v == dv){
		t = head->next;
//		free(head);
		head = t;
	}
	pre = head;
	if(head == NULL){
		printf("bo");
		return 0 ;
	}
	printf("%d", head->v);
	t = head->next;
	while(t != NULL){
		if(t->v == dv){
			pre->next = t->next;
			free(t);
		}
		else{
			pre = t;
		}
		t = pre->next;
	}
	// output
	head = head->next;
	while(head != NULL){
		printf(" %d", head->v);
		head = head->next;
	}
	return 0;
}


