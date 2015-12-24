/*
 * 前缀表达式.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char c[1000];
	gets(c);
	char op[500];
	double v[500];
	int opn=0, vn=0;
	bool type[500];
	int tn = 0;
	char * o = strtok(c, " ");
	while(o != NULL){
//		printf("%s\n", o);

		if(o[0] == '*' || o[0] == '-' ||
				o[0] == '+' || o[0] == '/'){
			op[opn++] = o[0];
			type[tn++] = 1;
		}
		else {
			v[vn++] = atof(o);
			type[tn++] = 0;
			while(tn > 1 && type[tn-2] == 0){
				double v1 = v[--vn];
				double v2 = v[--vn];
				switch(op[opn-1]){
				case '+':
					v[vn++] = v1+v2;break;
				case '-':
					v[vn++] = v2-v1;break;
				case '*':
					v[vn++] = v2*v1;break;
				case '/':
					v[vn++] = v2/v1;break;
				}
				tn -= 3;
				type[tn++] = 0;
//				printf("%f %f %f\n", v1, v2, v[vn-1]);
				opn --;
			}
		}
		o = strtok(0, " ");
	}
	printf("%f\n", v[0]);
	return 0;
}



