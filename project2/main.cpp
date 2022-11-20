#include <iostream>
#include "math.hpp"
using namespace std;

int main (int argc, char *argv[])
{
     if (argc < 3){
        cout<< "Usage: %s base exponent \n"<< argv[0] <<endl;
        return 1;
    }
    int a = *argv[1];
    int b = *argv[2];
    int exponent = pluse(a,b);
    cout << exponent <<endl;


}