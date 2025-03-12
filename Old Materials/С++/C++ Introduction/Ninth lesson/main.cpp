//
//  main.cpp
//  Ninth lesson
//
//  Created by Sokrat on 13.07.2022.
//
// Аргументы командной строки (???)

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        // Выводим список аргументов в цикле
        cout << "Argument " << i << " : " << argv[i] << endl;
    }
    return 0;
}
