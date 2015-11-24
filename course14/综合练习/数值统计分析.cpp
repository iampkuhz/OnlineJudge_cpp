#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
	int n;
	int a[102];
	int sum = 0, maxAbs = 0, max = 0, minAbs = 0, min = 0, sumP = 0, sumN = 0;
	scanf("%d", &n);
	for(int i = 0 ; i < n; i ++){
		scanf("%d", &a[i]);
		if(a[i] > 0 )
			sumP ++;
		else if(a[i] < 0)
			sumN ++;
		if(abs(a[i]) > maxAbs){
			maxAbs = abs(a[i]);
			max = a[i];
		}
		if(i == 0 || abs(a[i]) < minAbs){
			minAbs = abs(a[i]);
			min = a[i];
		}
		sum += a[i];
	}
	printf("%d\n%d\n%d\n%d\n%d\n", sumP, sumN, sum, max, min);
	return 0;
}
