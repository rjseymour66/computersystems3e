#include <stdio.h>

typedef unsigned char *byte_pointer;
/* This is a pointer to an unsigned char.
typedef is a way to give a name to a data type. 
Like declaring a variable, but uses the type name instead of a var name.*/


void test_show_bytes(int val);
void show_bytes(byte_pointer start, size_t len);
void show_int(int x);
void show_float(float x);
void show_pointer(void *x);

int main(void) {
   test_show_bytes(12345, 6);
}

void test_show_bytes(int val) {
   int ival = val;
   float fval = val;
   int *pval = &ival;
   show_int(ival);
   show_float(fval);
   show_pointer(pval);
}

void show_bytes(byte_pointer start, size_t len)
{
   int i;
   for (i = 0; i < len; i++)
      printf(" %.2x", start[i]);
   printf("\n");
}

void show_int(int x)
{
   printf("int:\t");
   show_bytes((byte_pointer)&x, sizeof(int));   /* '&x' creates a pointer to the location */
}                                               /*  holding the object indicated by variable x */

void show_float(float x)
{
   printf("float:\t");  
   show_bytes((byte_pointer)&x, sizeof(float)); /* sizeof(T) returns the number of bytes required to store */
}                                               /* an object of type T */

void show_pointer(void *x)
{
   printf("ptr:\t");
   show_bytes((byte_pointer)&x, sizeof(void *)); /* void * is a special kind of pointer with no associated type info */
}