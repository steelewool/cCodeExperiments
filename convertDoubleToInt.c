#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

int main (int argc, char** argv) {

  typedef union {
    double f;
    struct {
      uint64_t mantissa : 52;
      uint64_t exponent : 11;
      uint64_t sign     :  1;
    } parts;
    struct {
      uint64_t hex : 64;
    };
  } double_cast;
  
  double_cast dc;

  long unsigned int mantissa;
  int exponent;
  int sign;

  for (int i = 1; i < argc; ++i)
    printf ("argument: %d: %s\n", i, argv[i]);

  dc.f = (double)atof(argv[1]);
  dc.f = (double)strtod(argv[1], NULL);

  printf ("value: %g\n", dc.f);
  printf ("value as hex: 0x%lx: \n", dc.hex);

  printf ("sign: %d ",      dc.parts.sign);
  printf ("mantessa: %lu ", (long unsigned int)dc.parts.mantissa);
  printf ("exponent: %d\n", dc.parts.exponent);

  printf ("sign: 0x%x mantesia: 0x%lx exponent: 0x%x \n",
	  dc.parts.sign,
	  (long unsigned int)dc.parts.mantissa,
	  dc.parts.exponent);

  sign     = ((uint64_t)dc.f & 0x8000000000000000L) != 0; 
  exponent = ((uint64_t)dc.f & 0x7ff0000000000000L) >> 52;
  mantissa =  (uint64_t)dc.f & 0x000fffffffffffffL;

  printf ("sign: %d mantissa: %lu exponent: %d \n",
	  sign,
	  mantissa,
	  exponent);

  printf ("sign: 0x%x mantissa: 0x%lx exponent: 0x%x \n",
	  sign,
	  mantissa,
	  exponent);

  /*
  argument1 = strtol(argv[1], 0, 16);
  argument2 = strtol(argv[2], 0, 16);

  printf ("argument1: %d argument2: %d\n", argument1, argument2);

  value = (double) argument1  * pow((double)10,(double)argument2);
  */

  return 0;
}
