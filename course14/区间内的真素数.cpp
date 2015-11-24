/*
 * 区间内的真素数.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: hanzhe
 */

#include <stdio.h>
#include <math.h>

int cnt = 0;
bool isPrime(int k){
	if(k == 1)
		return false;
	int pmax = sqrt(k);
	for(int i = 2; i <= pmax; i ++)
		if(k % i == 0)
			return false;
	return true;
}
void isTruePrime(int k){
	int k1 = 0, k2 = k;
	while(k2 > 0){
		k1 = k1 * 10 + k2 % 10;
		k2 /= 10;
	}
//	printf("%d %d\n", k, k1);
	if(isPrime(k) && isPrime(k1)){
		if(cnt > 0)
			printf(",");
		printf("%d", k);
		cnt ++;
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n, &m);
	for(int i = n; i <= m ; i ++)
		isTruePrime(i);
	if(cnt <= 0)
		printf("No");
	return 0;
}



