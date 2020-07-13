#include <stdio.h>

typedef unsigned char *byte_pointer; 
/* This is a pointer to an unsigned char.
typedef is a way to give a name to a data type.
Like declaring a variable, but it uses the type name
instead of a var name. */

void show_bytes(byte_pointer start, size_t len);

int main(void) {
   short x = 12345;
   short mx = -x;

   printf("Printing the hex values of the following short data types:\n\n");

   printf(" %d:\t", x);
   show_bytes((byte_pointer) &x, sizeof(short));
   printf("\n");

   printf("%d:\t", mx);
   show_bytes((byte_pointer) &mx, sizeof(short));
}

void show_bytes(byte_pointer start, size_t len)
{
   int i;
   for (i = 0; i < len; i++)
      printf(" %.2x", start[i]);
   printf("\n");
}