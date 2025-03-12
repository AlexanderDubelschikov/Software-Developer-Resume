/* students.h */
#pragma once /* Защита от двойного подключения заголовочного файла */
#include <string>

class Students {
    public:
        // Запись данных о студенте в файл
        void save();
        // Деструктор класса Students
        ~Students();

        // Конструктор класса Students
        Students(std::string, std::string);
        // Установка имени студента
        void set_name(std::string);
        // Получение имени студента
        std::string get_name();

        // Установка фамилии студента
        void set_last_name(std::string);
        // Получение фамилии студента
        std::string get_last_name();

        // Установка промежуточных оценок
        void set_scores(int []);
        // Получение массива с промежуточными оценками
        int *get_scores();
        // Получение строки с промежуточными оценками
        std::string get_scores_str(char);

        // Установка среднего балла
        void set_average_ball(float);
        // Получение среднего балла
        float get_average_ball();
    private:
        // Промежуточные оценки
        int scores[5];
        // Средний балл
        float average_ball;
        // Имя
        std::string name;
        // Фамилия
        std::string last_name;
};
