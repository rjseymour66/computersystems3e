#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main () {

   printf("Displays a list of 8-bit data types for your current machine (64-bit)\n\n");

   printf("Data type\t\tMinimum\t\t\tMaximum\n");
   printf("[signed] char\t\t%d\t\t\t%d\n", SCHAR_MIN, SCHAR_MAX);
   printf("unsigned char\t\t0\t\t\t%d\n", UCHAR_MAX);
   printf("\n");

   printf("[signed] short\t\t%d\t\t\t%d\n", SHRT_MIN, SHRT_MAX);
   printf("unsigned short\t\t0\t\t\t%d\n", USHRT_MAX);
   printf("\n");

   printf("[signed] int\t\t%d\t\t%d\n", INT_MIN, INT_MAX);
   printf("unsigned int\t\t0\t\t\t%d\n", UINT_MAX);
   printf("\n");

   printf("[signed] long\t\t%ld\t%ld\n", LONG_MIN, LONG_MAX);
   printf("unsigned long\t\t0\t\t\t%ld\n", ULONG_MAX);
   printf("\n");
/*
   printf("[signed] int32_t\t\t%ld\t\t%ld\n", INT32_MIN, INT32_MAX);
   printf("unsigned int32_t\t\t0\t\t%d\n", UINT_FAST32_MAX);
   printf("\n");

   printf("[signed] int64_t\t\t%lld\t\t%lld\n", INT64_MIN, INT64_MAX);
   printf("unsigned int64_t\t\t0\t\t%llu\n", UINT64_MAX);
   printf("\n");  
*/

   return 0;
}







   