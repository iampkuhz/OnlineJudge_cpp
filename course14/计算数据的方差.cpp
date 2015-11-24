#include <stdio.h>

int main(){
	int n;
	double *p;
	scanf("%d",&n);
	int i = 0;
	p = new double[n];
	double avg = 0.0;
	for(i = 0 ;i < n; i ++)
	{
		double v;
		scanf("%lf",&v);
		p[i] = v;
		avg += v;
	}
	avg /= n;
	double d = 0.0;
	for(i = 0 ; i < n; i ++)
		d += (avg - p[i])*(avg - p[i]);
	d /= n;
	printf("%.5lf %.5lf", avg, d);
	return 0;

}
