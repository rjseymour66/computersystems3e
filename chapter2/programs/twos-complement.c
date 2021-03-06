#include <stdio.h>

typedef unsigned char *byte_pointer;
/* This is a pointer to an unsigned char.
typedef is a way to give a name to a data type.
Like declaring a variable, but it uses the type name
instead of a var name. */

void show_bytes(byte_pointer start, size_t len);

int main(void)
{
   short x = 12345;
   short mx = -x;

   printf("Printing the hex values of the following short data types:\n\n");

   printf(" %d:\t", x);
   show_bytes((byte_pointer)&x, sizeof(short));
   printf("\n");

   printf("%d:\t", mx);
   show_bytes((byte_pointer)&mx, sizeof(short));

   printf("\nConvert signed to unsigned\n");
   printf("Casting keeps the bit values identical but changes how the bits are interpreted.\n\n");

   short int v = -12345;
   unsigned short uv = (unsigned short)v;
   printf("v = %d, uv = %u\n", v, uv);

   printf("\n");

   printf("Here, we are casting UMax to signed:\n\n");

   unsigned u = 4294967295u; /* UMax */
   int     tu = (int)u;
   printf("u = %u, tu = %d\n", u, tu);

   printf("\n");
   printf("More examples:\n");
   int t1 = -5;
   unsigned ut1 = (unsigned int)t1;
   printf("t1 = %d, ut1 = %u", t1, ut1);

   printf("\n");

}

void show_bytes(byte_pointer start, size_t len)
{
   int i;
   for (i = 0; i < len; i++)
      printf(" %.2x", start[i]);
   printf("\n");
}