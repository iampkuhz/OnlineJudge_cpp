#include <stdio.h>

int a[30][15];
int find(int m, int n){
	if(m <= 1 || n <= 1)
		return 1;
	if(a[m][n] > 0)
		return a[m][n];
	if(m >= n)
		a[m][n] =  find(m-n, n) + find(m, n-1);
	else a[m][n] =  find(m, n-1);
	return a[m][n];
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i = 0 ; i < 30;i ++)
		for(int j = 0 ; j < 15; j ++)
			a[i][j] = -1;
	while(t--){
		int m, n;
		scanf("%d %d", &m, &n);
		printf("%d\n", find(m, n));
	}
	return 0;
}
