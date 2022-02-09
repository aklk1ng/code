#include <stdio.h>
#include <string.h>
#define YEAR "This is a joke" 
int main(void)
{
	float years;
	printf("Please enter your years: \n");
	scanf("%s, %years");
	printf("%s\n", YEAR);
	printf("%zd", sizeof (YEAR));
	
	return 0;
 } 
