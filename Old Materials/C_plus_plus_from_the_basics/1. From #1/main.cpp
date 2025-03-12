// Первый блок уроков, посвященный самым базовым вещам.

// Escape последовательности
/*
 
 \n Перейти в начало следующей строки
 \t Перейти к следующей позиции табуляции
 
 //////
 
 \\ Вывести обратный слеш
 \" Вывести двойную кавычку
 \' Вывести одинарную ковычку
 
 */

#include <iostream> // Стандартная библиотека
using namespace std; // Стандартное прострнаство имен

int main() // Основная функция
{

    setlocale(LC_ALL, "Rus"); // Настраиваем язык вывода в консоль
    cout << "Привет мир!\n"; // Вывод в коносоль Привет мир!
    cout << "Привет мир!\t\t\t\t\t\n";
    
    int a = 1;
    double b = 2.32;
    float c = 2.1;
    char d = 'C';
    bool e = true;
    const int COUNT_DAYS_IN_WEEK = 7;
    const char NEW_LINE = '\n';
    const char TAB = '\t';
    
    cout << a << "|" << b << "|" << c << "|" << d << "|" << e << "|" << COUNT_DAYS_IN_WEEK << NEW_LINE;
    
    cin >> a;
    cout << a << NEW_LINE;
    
    cout << TAB <<"Конец проекта" << NEW_LINE;
    
}

