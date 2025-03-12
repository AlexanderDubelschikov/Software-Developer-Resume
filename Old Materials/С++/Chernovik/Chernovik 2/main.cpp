//


#include <iostream>
#include <string.h>
using namespace std;

int func(void);

int main(int argc, const char * argv[])
{
    int a = func();
    cout << a << endl;
}
    

int func(void)
{
    char  Text[]="abcd";
    return sizeof(Text);
}
