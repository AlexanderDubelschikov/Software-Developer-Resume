//
//  main.cpp
//  Second Lesson dz
//
//  Created by Sokrat on 13.07.2022.
//
// Типы данных

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    float a = 2.2;
    float b = 2.2;
    float d = a*b;
    cout << d << endl;
    cout << "Введи число: ";
    cin >> a;
    cout << "Введи число: ";
    cin >> b;
    d = a*b;
    cout << d << endl;
}
