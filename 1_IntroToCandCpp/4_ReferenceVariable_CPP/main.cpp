#include <iostream>

using namespace std;

int main()
{
    int a=10;
    int &r = a; //r is an alias to a
    //When a variable is declared as reference variable and should be initialised at the time of declaration

    int b=25;
    r = b; //This is assignment and not initialisation. Therefore a is assigned with value of b;

    printf("%d %d\n",r,a);
    return 0;
}

//NOTE
//1. Conceptually, reference is just another name and it doesnt consume memory
