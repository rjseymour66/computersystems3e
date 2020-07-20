#include <stdio.h>

typedef unsigned char *byte_pointer;
/* This is a pointer to an unsigned char.
typedef is a way to give a name to a data type. 
Like declaring a variable, but uses the type name instead of a var name.*/

void show_bytes(byte_pointer start, size_t len);

int main() {

   int x = 53191;
   short sx = (short)x;
   int y = sx;

   printf("x\t\t%d\t", x);
   show_bytes((byte_pointer) &x, sizeof(int));

   printf("(short)x\t%d\t", sx);
   show_bytes((byte_pointer) &sx, sizeof(short));

   printf("recasted x\t%d\t", y);
   show_bytes((byte_pointer) &y, sizeof(int));

   return 0;
}

void show_bytes(byte_pointer start, size_t len)
{
   int i;
   for (i = 0; i < len; i++)
      printf(" %.2x", start[i]);
   printf("\n");
}