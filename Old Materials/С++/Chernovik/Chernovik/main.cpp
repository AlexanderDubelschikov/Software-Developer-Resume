//
//  main.cpp
//  Chernovik
//
//  Created by Sokrat on 09.08.2022.
//

#include <iostream>
#include <string>
using namespace std;

int* func(int *a, int*b, int L);

int main(int argc, const char * argv[])
{

    int a[16]
    {
        1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
    };
    
    int b[16]{
        1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
    };
    
    int L=16;
    
    int* pointer = func(a,b,L);
    
    for (int i=0; i<16; i++)
    {
        cout << pointer[i] << endl;
    }
    
  
    
    return 0;
}

int* func(int *a, int*b, int L)
{
    static int c[16];
    int i;
    L=(L>16) ? L : 16;
    for (i=0; i<L; i++)
    {
        c[i]=a[i]+b[i];
    }
    return c;
}
