#include <stdio.h>

/* pointer is a special type of variable that can hold memory addresses */

int main() {

   int value = 19;
   int *pValue = &value;

   printf("Address \t Name \t Value \n");
   printf("%p \t %s \t %d \n", pValue, "value", value);
   printf("%p \t %s\t %p \n", &pValue, "pValue", pValue);

   printf("\n*pValue: %d \n", *pValue);
   /* go to the variable that it is pointing to and get the value of it */

   *pValue = 71;
   printf("\n*pValue: %d \n", *pValue);
   printf("\n*value: %d \n", value);


   return 0;
}