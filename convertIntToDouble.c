#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc, char** argv) {

  int argument1, argument2;
  double value;

  for (int i = 1; i < argc; ++i)
    printf ("argument: %d: %s\n", i, argv[i]);

  argument1 = strtol(argv[1], 0, 16);
  argument2 = strtol(argv[2], 0, 16);

  printf ("argument1: %d argument2: %d\n", argument1, argument2);

  value = (double) argument1  * pow((double)10,(double)argument2);

  printf ("value: %g\n", value);

  return 0;
}
