#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct my{
	int id;
	char c;
	my * next;
};
int main()
{
	struct my fir;
	fir.next = NULL;
	struct my *p = (my*)malloc(sizeof(my)), *p2 = (my*)malloc(sizeof(my));
	p->c = 's';
	p->id = 2;
	p->next = p2;
	p2->c = 'l';
	p2->id = 4;
	p2->next = NULL;

	struct my *q;
	q = p;
	while(q != NULL){
		printf("%d %c\n", q->id, q->c);
		q = q->next;
	}
    return 0;
}
