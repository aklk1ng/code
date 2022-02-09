#include <stdio.h>
void one_three(void); //声明函数 
void two(void); //声明函数

void one_three(void) //定义函数
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
