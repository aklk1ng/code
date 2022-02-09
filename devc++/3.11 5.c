#include <stdio.h>
#define SEC_PER_YEARS 3.156e7
int main(void)
{
	int age;
	float seconds;
	printf("Please enter your age: ");
	scanf("%d", &age);
	seconds = age * SEC_PER_YEARS;
	printf("That's %e seconds in %d age.\n", seconds, age);
	return 0;
	
	
	
}
