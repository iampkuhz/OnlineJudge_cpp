/*
 * 链表合并排序.cpp
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
	node * head = NULL, * pre = NULL;
	int sum = 0;
	scanf("%d", &k);
	sum += k;
	while(k--){
		node * t = (node*)malloc(sizeof(node));
		scanf("%d", &t->v);
		if(head == NULL){
			head = pre = t;
		}
		else pre->next = t;
		pre = t;
	}
	scanf("%d", &k);
	sum += k;
	while(k--){
		node * t = (node*)malloc(sizeof(node));
		scanf("%d", &t->v);
		if(head == NULL){
			head = pre = t;
		}
		else pre->next = t;
		pre = t;
	}
//	node * thead = head;
//	printf("%d", thead->v);
//	while(thead->next != NULL){
//		printf(" %d", thead->next->v);
//		thead = thead->next;
//	}
//	printf("\n");

	//sort
	for(int i = sum-1; i>=1; i--){
		node * t = head;
		pre = NULL;
//		printf("%d\n", i);
		int k = i;
		while(k--){
//			printf("i%d\n", i);
			if(t->v > t->next->v){
//				printf("i%d\n", i);
				// pre, t, t->next, t->next->next
				node * nn = t->next->next;
				node * n = t->next;
				if(pre != NULL)
					pre->next = n;
				else head = n;
				n->next = t;
				t->next = nn;
				pre = n;
			}
			else{
				pre = t;
				t = t->next;
			}
		}
//		node * thead = head;
//		printf("%d", thead->v);
//		while(thead->next != NULL){
//			printf(" %d", thead->next->v);
//			thead = thead->next;
//		}
//		printf("\n");
	}
	printf("%d", head->v);
	while(head->next != NULL){
		printf(" %d", head->next->v);
		head = head->next;
	}
	return 0;
}


