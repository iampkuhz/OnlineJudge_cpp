#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
  {char name[3];
  char tab1;
   int number;
   char tab2;
   float score;
   }stu[4],student[4];
int main()
{FILE *fp;
 int i;
 if((fp=fopen("/home/hanzhe/Downloads/tmp/result/bad_id","r"))==NULL)
  {printf("can not open it!!\n");
   exit(-1);
  }
 for(i=0;i<4;i+=2)
 {
  fseek(fp,i*sizeof(struct student),0);
  fread(&student[i].name, sizeof(char) * 2, 0, fp);
  printf("str:%s\n", student[i].name);
//  fread(&student[i],sizeof(struct student),1,fp);
//  printf("str:\"%s\"\tid:\"%d\"\tval:\"%lf\"\nXXXX\n",student[i].name,student[i].number,student[i].score);
  printf("%%%\n");
  }
 return 0;
}
