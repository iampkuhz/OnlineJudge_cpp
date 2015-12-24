/*
 * 算24.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: hanzhe
 */
#include <cmath>


#include <stdio.h>
bool find(double a, double b, double tar){
	return fabs(a*b - tar) < 1E-4 || fabs(a+b - tar) < 1E-4 || (b!=0 && fabs(a -tar*b)< 1E-4) || fabs(a-b - tar) < 1E-4 || fabs(b-a - tar) < 1E-4
			|| (a!=0 && fabs(b-a*tar) < 1E-4);
}
bool find(double a, double b, double c, double t){
	return  (c!=0&&find(a,b, t/c)) || (c!=0 &&find(a,b, t*c)) || find(a,b,t-c) || find(a,b,t+c)
			|| find(a,b,c-t)|| (c!=0 &&find(a,b,c/t));
}
bool find2(double a, double b, double c, double t){
	return find(a,b,c,t) || find(a,c,b,t) || find(b,c,a,t);
}
bool find(double a, double b, double c, double d, double t){
	return find2(a*b, c,d, t) || find2(a+b, c,d, t) || find2(a-b, c,d, t) ||
			find2(b-a, c,d, t) || (b!=0 && find2(a/b, c,d, t)) ||(a!=0 && find2(b/a, c,d, t));
}
bool find2(double a, double b, double c, double d, double t){
	return find(a,b,c,d,t) || find(a,c,b,d,t) || find(a,d,c,b,t) ||
			find(b,c, a, d,t) || find(b,d, a,c,t) || find(c,d,a,b,t);
}


int main(){
	while(true){
		double a,b,c,d;
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		if(a == 0 && b == 0 &&  c == 0 && d == 0)
			return 0;
//		if(Test(4) )
//			printf("Yes:\n");
		if(find2(a,b,c,d,24))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

