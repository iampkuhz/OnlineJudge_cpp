
#include<stdio.h>
#include<string.h>
int main()
{
  int n,i,j,k=0,t,b,c,d,m;
  char a[100][100]={0},s[100]={0};
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%s",a[i]);
    getchar();
  }
  for(i=0;i<n;i++)
  {
    c=0;
    k=0;
    t=strlen(a[i]);
    for(j=0;j<t;j++)
    {
      b=a[i][j]>= 'A'?a[i][j]-'A'+10:a[i][j]-'0';
      c=c*14+b;
    }
    d=0;
    while(c>0)
    {
      s[k++] = c%7+'0';
      c=c/7;
    }
    if(k == 0)
      printf("0");
    else
    {
      for(m=k-1;m>0;m--)
      {
        printf("%c",s[m]);
      }
      if(i == n-1)
        printf("%c",s[0]);
      else
        printf("%c ",s[0]);
    }
    memset(a[i],0,t);
    memset(s,0,strlen(s));
  }
}
