#include <stdio.h>
#include <string.h>
#define HAPPY "You're so beautiful!"
int main(void)
{
	char name[40];
	printf("Please enter your name: ");
	scanf("%s", name);
	printf("Hello! %s\n", HAPPY);
	printf("Look!Threr're %zd letters occupies %zd memory cells.\n",
	        strlen(name), sizeof (name));
	printf("The phrase of happy has %zd letters and occupies %zd memory cells.\n",
	        strlen(HAPPY), sizeof (HAPPY)); //sizeof���ͺ���Ϊ��������ҪԲ���ţ���Ϊ�ض�������ҪԲ���ţ����п��ޣ� 
	
	return 0;
}
