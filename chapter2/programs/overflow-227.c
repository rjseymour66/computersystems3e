#include <stdio.h>

/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y);

int main () {

   uadd_ok()

   return 0;
}

int uadd_ok(unsigned x, unsigned y) {
   unsigned sum = x + y;
   return sum >= x;
}