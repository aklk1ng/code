#include <stdio.h>
#include <string.h>
#define YEAR "you're beautiful" 
int main(void)
{
	char name[40];
	printf("Please enter your name: ");
	scanf("%s", &name);
	printf("%s and your name has %d bites and %d number,\n", YEAR, sizeof (YEAR), strlen (YEAR));
	return 0;
}
