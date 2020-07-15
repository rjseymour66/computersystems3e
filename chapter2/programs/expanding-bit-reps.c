#include <stdio.h>

typedef unsigned char *byte_pointer;
/* This is a pointer to an unsigned char.
typedef is a way to give a name to a data type. 
Like declaring a variable, but uses the type name instead of a var name.*/

void show_bytes(byte_pointer start, size_t len);

int main() {

   short sx = -12345;         /* -12345 */
   unsigned short usx = sx;   /* 53191 */
   int x = sx;                /* -12345 */
   unsigned ux = usx;         /* 53191 */

   /* 16-bit word */
   printf("sx  = %d:\t", sx);
   show_bytes((byte_pointer) &sx, sizeof(short));
   
   printf("usx = %u:\t", usx);
   show_bytes((byte_pointer) &usx, sizeof(unsigned short));

   /* 32-bit word */
   printf("x   = %d\t", x);
   show_bytes((byte_pointer) &x, sizeof(int));

   printf("ux  = %u:\t", ux);
   show_bytes((byte_pointer) &ux, sizeof(unsigned));

   printf("*******************************\n\n");

   short dx = -12345;
   unsigned uy = dx;

   printf("uy = %u:\t", uy);
   show_bytes((byte_pointer) &uy, sizeof(unsigned));
}

void show_bytes(byte_pointer start, size_t len)
{
   int i;
   for (i = 0; i < len; i++)
      printf(" %.2x", start[i]);
   printf("\n");
}