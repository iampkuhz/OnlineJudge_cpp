#include <stdio.h>
#include <string.h>
int main()
{
    int t,n;
    int i,j,k,l,m,q;
    char *temp;
//    int * q1[100];
//
//    for(int i = 0 ;  i < 10 ; i ++)
//    	printf("%d %x,", q1[i], q1[i]);
//    printf("\nooo\n");
//    scanf("%d", q1[0]);
//    for(int i = 0 ;  i < 3 ; i ++)
//    	printf("%d %x,", q1[i], q1[i]);
//    printf("\n");
    scanf("%d",&t);
    for(i=0;i<=t-1;i++)
    {
        scanf("%d",&n);
        char *p[100];//定义指针数组
        for(j=0;j<=n-1;j++)
        {
        	char ts[100];
            scanf("%s",ts);//输入字符串
            p[i] = ts;
            getchar();//输入换行符
            printf("str:%s, %x\n",p[i], ts);
        }
        for(int j = 0 ; j < n; j ++)
        	printf("%x sss:%s\n", p[i], p[i]);

        printf("\n");
        for(k=0;k<n-1;k++)//字符串排序
        {
            l=k;
            for(m=l+1;m<n;m++)
            {
                if(strcmp(p[l],p[m])>0)
                    l=m;
            }
            if(l!=k)
            {
                temp=p[k];
                p[k]=p[l];
                p[l]=temp;
            }
        }
        for(q=0;q<=n-1;q++)//输出排序后的字符串，一个循环输出一次
        {
            printf("result:%s\n",p[q]);
          }
        printf("\n");
    }

    return 0;
}
