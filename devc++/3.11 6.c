#include <stdio.h>
#define SEC_PER_YEARS 3.0e-23
#define SEC_PER_NUMBER 950
int main(void)
{
  double counts, number;
  printf("Please enter the water's counts: "); 
  scanf("%lf, &counts");
  number = counts * SEC_PER_NUMBER /SEC_PER_YEARS;
  printf("That's %g water counts include %e number.\n", counts, number);
  return 0;
 
 } 
