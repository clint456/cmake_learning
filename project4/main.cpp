#include <iostream>
#include <config.h>

#ifdef USE_MYMATH
  #include "selfMath.hpp"
#else
  #include <math.h>
#endif

using namespace std;

int main ()
{
    cout << "pleas enter two number !" <<endl;
    int a,b;
    cin >> a >> b;
    int exponent;
#ifdef USE_MYMATH
    cout <<"Now we use our own Math library. \n";
    exponent = pluse(a,b);
#else
    cout << "Now we use the standard library. \n";
    exponent = pow(a,b);
#endif
   
    cout << "a an b is "<< exponent <<endl;


}