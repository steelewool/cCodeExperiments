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

  typedef union {
    double d;
    struct {
      uint64_t mantissa : 52;
      uint64_t expo : 11;
      uint64_t sign : 1;
    } parts;
    long int binary;
  } doubleBits;

  doubleBits bitInterpreation;
  double value;
  int exponent;
  double mantissa;

  bitInterpreation.d = value = atof(argv[1]);

  printf ("value: %g \n", value);

  exponent = (value == 0) ? 0 : (int)(1 + log10(fabs(value)));
  mantissa = value * pow(10,-(exponent));

  printf ("exponent: %d \n", exponent);
  printf ("mantissa: %g \n", mantissa);
  
  printf ("bitInterpreation.binary: 0x%lx \n",
	  bitInterpreation.binary);

  printf ("bitInterpreation.mantissa: %d \n",
	  bitInterpreation.parts.mantissa);

}
