/*
 * 生日相同 2.0版本.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: hanzhe
 */


#include <stdio.h>
#include <string.h>

	int n;
	char name[190][25];
	int mdIds[13][33][190];
	int mdCnt[13][33];

int nameCmp(char * n1, char * n2){
	if(strlen(n1) > strlen(n2))
		return 1;
	else if(strlen(n1) < strlen(n2))
		return -1;
	else return strcmp(n1, n2);
}
void mySort(int * ids, int s, int e){
	if(s > e)
		return;
	int pvid = ids[s];
	int ps = s, pe = e;
	while(ps < pe){
		while(ps < pe && nameCmp(name[ids[pe]], name[pvid]) > 0)
			pe --;
		if(ps < pe)
			ids[ps ++ ] = ids[pe];
		while(ps < pe && nameCmp(name[ids[ps]], name[pvid]) < 0)
			ps ++;
		if(ps < pe)
			ids[pe --] = ids[ps];
	}
	ids[pe] = pvid;
//	printf("%d %d %d\n", s, e, pe);
	mySort(ids, s, pe-1);
	mySort(ids, pe+1, e);
}

int main(){
	scanf("%d", &n);
	for(int i = 0 ; i < 13; i ++)
		for(int j = 0; j < 33; j ++)
			mdCnt[i][j] = 0;
	for(int i = 0 ;i < n; i ++){
		int m, d;
		scanf("%s %d %d", name[i], &m, &d);
		mdIds[m][d][mdCnt[m][d] ++ ] = i;
	}
	int cnt = 0;
	for(int m = 1 ; m < 13; m ++)
		for(int d = 1; d < 33; d ++)
			if(mdCnt[m][d] > 1){
				mySort(mdIds[m][d], 0, mdCnt[m][d]-1);
				printf("%d %d", m, d);
				for(int i = 0 ; i < mdCnt[m][d]; i ++)
					printf(" %s", name[mdIds[m][d][i]]);
				printf("\n");
				cnt = 1;
			}
	if(cnt == 0)
		printf("None\n");
	return 0;
}

