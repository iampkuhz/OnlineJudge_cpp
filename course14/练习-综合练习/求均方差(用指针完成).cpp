//
// Created by hanzhe on 15-12-16.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct va{
	double v;
	va * next;
};
int main(){
	int k,n;
	double a[200];
	scanf("%d", &k);
	while(k--){
		scanf("%d",&n);
		va * head = NULL, * pre = NULL;
		double sum = 0;
		for(int i = 0 ; i < n; i ++){
			va * t = (va*) malloc(sizeof(va));
			t->next = NULL;
			if(head == NULL){
				head = pre = t;
			}
			else {
				pre->next = t;
				pre = t;
			}
			scanf("%lf",&t->v);
			//printf("v:%.5f\n", t->v);
			sum += t->v;
		}
		sum /= n;
		double re = 0;
		va * t = head;
		while(t != NULL){
			//printf("v:%.5f sum:%lf\n", t->v, sum);
			re += (t->v-sum)*(t->v-sum);
			//printf("%.5f\n", t->v);
			t = t->next;
		}
		//printf("%.5f\n", re);
		printf("%.5f\n", sqrt(re/n));
	}

	return 0;

}
