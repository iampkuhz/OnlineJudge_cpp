/*
 * 1017 学分绩点.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: hanzhe
 */

#include <stdio.h>

double getPT(int point){
	if(point >= 90)
		return 4.0;
	else if(point >= 85)
		return 3.7;
	else if(point >= 82)
		return 3.3;
	else if(point >= 78)
		return 3.0;
	else if(point >= 75)
		return 2.7;
	else if(point >= 72)
		return 2.3;
	else if(point >= 68)
		return 2.0;
	else if(point >= 64)
		return 1.5;
	else if(point >= 60)
		return 1.0;
	return 0;
}
int main(){
	int n;
	int sc[15];
	int pt[15];
	double avg = 0.0;
	double psum = 0;
	scanf("%d", &n);
	for(int i = 0 ;i < n; i ++){
		scanf("%d", &pt[i]);
		psum += pt[i];
	}
	for(int i = 0 ;i < n; i ++){
		scanf("%d", &sc[i]);
		avg += 1.0 * pt[i] * getPT(sc[i]);
	}
	avg /= psum;

	printf("%.2f", avg);

}


