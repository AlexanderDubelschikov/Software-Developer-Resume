//
//  main.cpp
//  Fifth lesson
//
//  Created by Sokrat on 13.07.2022.
//
// Массивы

#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::string students[10] = {
        "Иванов", "Петров", "Сидоров",
        "Ахмедов", "Ерошкин", "Выхин",
        "Андеев", "Вин Дизель", "Картошкин", "Чубайс"
    };
    std::cout << students << std::endl; // Пытаемся вывести весь массив непосредственно
    std::cout << students[0] <<  std::endl;
    for (int i = 0; i < 10; i++) {
           std::cout << students[i] << std::endl;
       }
    
    int arr[10];

           // Заполняем массив с клавиатуры
           for (int i = 0; i < 10; i++) {
               cout << "[" << i + 1 << "]" << ": ";
               cin >> arr[i];
           }

           // И выводим заполненный массив.
           cout << "\nВаш массив: ";

           for (int i = 0; i < 10; ++i) {
               cout << arr[i] << " ";
           }

           cout << endl;
    return 0;
}
