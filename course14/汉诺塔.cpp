/*
 * h(n,a,b,c) = h(n-1, a,c,b) + (a->c) + h(n-1, b,c,a)
 * 汉诺塔.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: hanzhe
 */

#include <stdio.h>

void Han(int n, char a, char b, char c){
	if(n == 1){
		printf("%c->%c\n", a, c);
		return;
	}
	Han(n-1, a, c, b);
	printf("%c->%c\n", a, c);
	Han(n-1, b, a, c);
}

int main(){
	int n;
	scanf("%d",&n);
	Han(n, 'A', 'B', 'C');
}


