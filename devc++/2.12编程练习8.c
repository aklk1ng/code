#include <stdio.h>
void one_three(void); //�������� 
void two(void); //��������

void one_three(void) //���庯��
{
	printf("one\n");
}
void two(void)
{
	printf("two\nthree\n");
}
int main()
{
	printf("starting now\n");
	one_three();
	two();
	printf("done!\n");
	
	getchar();
	return 0;
}
