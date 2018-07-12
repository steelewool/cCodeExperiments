#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int main (int argc, char **argv) {

  /*
   *exp = (arg == 0) ? 0 : (int)(1 + std::log10(std::fabs(arg) ) );
   return arg * pow(10 , -(*exp));    
  */

  double value;
  int    exponent;
  double mantissa;
  int    intMantissa;

  value = atof(argv[1]);

  printf ("value: %g \n", value);

  exponent = (value == 0) ? 0 : (int)(/* 1 */ -9 + log10(fabs(value)));
  mantissa = value * pow(10,-(exponent));
  intMantissa = mantissa;

  printf ("exponent:    %d \n",   exponent);
  printf ("exponent:    0x%8x \n", exponent);
  printf ("mantissa:    %g \n",   mantissa);
  printf ("intMantissa: %d \n",   intMantissa);
  printf ("intMantissa: 0x%8x \n", intMantissa);

}
