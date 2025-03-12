/*
Составить программу, которая будет считывать введённое пятизначное число. После чего, каждую цифру этого числа необходимо вывести в новой строке. Использовать операцию %.

 */

#include <iostream>

int main()
{
    int *a = new int;
    int *b = new int[5];

    
    std::cout << "Введите пятизначное число: " << std::endl;
    std::cin >> *a;
    if (*a>9999 && *a<100000)
    {
    
        for (int i=4; i>-1; i--)
        {
            b[i]=*a%10;
            *a=*a/10;

        }
        
        for (int i=0; i<5; i++)
        {
            std::cout << b[i] << std::endl;
        
        }
    }
    else
        std::cout<< "Число не 5-значное!" << std::endl;

    delete [] b;
    delete a;
}
