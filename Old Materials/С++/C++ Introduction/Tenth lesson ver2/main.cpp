/* main.cpp */
#include <iostream>
#include "students.h"

int main(int argc, char *argv[])
{
    // Локальная переменная, хранящая имя ученика
    std::string name;
    // И его фамилию
    std::string last_name;

    // Ввод имени
    std::cout << "Name: ";
    getline(std::cin, name);
    // И фамилии
    std::cout << "Last name: ";
    getline(std::cin, last_name);

    // Передача параметров конструктору
    Students *student = new Students(name, last_name);

    // Оценки
    int scores[5];
    // Сумма всех оценок
    int sum = 0;

    // Ввод промежуточных оценок
    for (int i = 0; i < 5; ++i) {
        std::cout << "Score " << i+1 << ": ";
        std::cin >> scores[i];
        // суммирование
        sum += scores[i];
    }
    // Сохраняем промежуточные оценки в объект класса Student
    student->set_scores(scores);

    // Считаем средний балл
    float average_ball = sum / 5.0;
    // Сохраняем средний балл
    student->set_average_ball(average_ball);

    // Выводим данные по студенту
    std::cout << "Average ball for " << student->get_name() << " "
         << student->get_last_name() << " is "
         << student->get_average_ball() << std::endl;
    // Удаление объекта student из памяти
    student->save();
    delete student;
    return 0;
}
