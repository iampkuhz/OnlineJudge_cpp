/*
 * 连续整数区域上确界.cpp
 *
 *  Created on: Dec 16, 2015
 *      Author: hanzhe
 */

#include <stdio.h>

int n, k;
int a[30];
bool get(int sum, int times){
	if(sum == 0 && times >= 0)
		return true;
	if(times <=0 || sum > times*a[n-1])
		return false;

	for(int i = n-1; i >=0 ; i--)
		if(sum >= a[i] && get(sum-a[i], times-1))
			return true;
	return false;
}
int main(){
	scanf("%d,%d", &n,  &k);
	while(true){
		bool jump = true;
		for(int i = 0 ; i < n; i ++){
			scanf("%d", &a[i]);
			jump = jump && (a[i] == 0);
		}
		if(jump)break;
		int j = 1;
		while(get(j, k))
			j ++;
		printf("%d\n", j-1);
	}
	return 0;
}


