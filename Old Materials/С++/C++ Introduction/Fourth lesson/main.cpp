//
//  main.cpp
//  Fourth lesson
//
//  Created by Sokrat on 13.07.2022.
//
// Циклы

#include <iostream>
using namespace std;

int main()
{
    int i; // счетчик цикла
    int sum = 0; // сумма чисел от 1 до 1000.
    setlocale(0, "");
    for (i = 1; i <= 1000; i++) // задаем начальное значение 1, конечное 1000 и задаем шаг цикла - 1.
    {
        sum = sum + i;
    }
    cout << "Сумма чисел от 1 до 1000 = " << sum << endl;
    i = 1;
    while (i < 1000)
     {
         i++;
         sum += i;
     }
     cout << "Сумма чисел от 1 до 1000 = " << sum << endl;
    
    do {// выполняем цикл.
        i++;
        sum += i;
    } while (i < 1000); // пока выполняется условие.
    cout << "Сумма чисел от 1 до 1000 = " << sum << endl;
    
    return 0;
}
