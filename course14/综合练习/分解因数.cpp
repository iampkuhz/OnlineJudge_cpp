/*
 * 分解因数.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */
#include <stdio.h>
#include <stdlib.h>
int find(int n, int max){
	if(n < 2)
		return 0;
	int re = 0;
	for(int i = 2; i <= n/2 && i <= max; i++)
		if(n % i == 0)
			re += find(n/i, i);
	re += n <= max ? 1:0;
	//printf("n:%d m:%d re:%d\n", n, max, re);
	return re;
}
int main(){
	int k;
	scanf("%d", &k);
	while(k--){
		int n;
		scanf("%d", &n);
		int re = find(n, n);
		printf("%d\n", re);
	}
	return 0;

}



