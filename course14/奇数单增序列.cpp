/*
 * 奇数单增序列.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: hanzhe
 */

#include <stdio.h>

void mySort(int * a, int s, int e){
	if(s + 1 > e)
		return;
	int sv = a[s];
	int ps = s, pe = e;
	while(ps < pe){
		while(pe > ps && a[pe] >= sv)
			pe --;
		if(pe > ps)
			a[ps++] = a[pe];
		while(pe > ps && a[ps] <= sv)
			ps ++;
		if(pe > ps)
			a[pe--] = a[ps];
	}
	a[pe] = sv;
//	printf("%d %d %d\n", s, e, pe);
	mySort(a, s, pe-1);
	mySort(a, pe+1, e);
}
int main(){
	int n, num = 0;
	int a[600];
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i ++){
		int t;
		scanf("%d", &t);
		if(t % 2 == 1)
			a[num ++] = t;
	}
//	printf("%d\n", num);
	mySort(a, 0, num-1);
	printf("%d", a[0]);
	for(int i = 1 ; i < num; i ++)
		printf(",%d", a[i]);
}



