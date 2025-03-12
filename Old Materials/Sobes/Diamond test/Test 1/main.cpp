//
//  main.cpp
//  Test 1
//
//  Created by Sokrat on 22.09.2022.
//
//
/*
 Имеется структура
 struct hdr {
     float angle; // значения углов положения антенны, диапазон
     значений от 0 до 360 градусов
     float data; // данные для обработки
     int64_t time; // метка времени, для которой получены данные
 };
 В процессе работы антенна вращается с некоторой скоростью. С
 некоторой периодичностью (например, 100 Гц) считываются показания
 датчика положения антенны, время и данные для обработки. Показания
 датчика положения антенны зашумлены. Необходимо написать
 функцию/класс сглаживания (скользящего среднего) положения
 антенны, не искажая привязку данных ко времени (данные привязать к
 центру окна осреднения). Размер окна настраивается (от 3 до 21).
 */

#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <cmath>
#include <vector>
#include <mutex>
#include <string>
using namespace std;

//Массив для записи поворота угла
vector <float> vAngle = {0};
//Массив для записи скользящих средних, если возникнет потребность в их использовании
vector <float> maAngle = {0};
//Массив, чтобы сохранять данные, которые посылает антена, на случай такой потребности
vector <float> vData = {0};
//Массив, для сохранения времени меток
vector <int64_t> vTime = {0};
mutex mtx;

struct hdr
{
    float angle;
    float data;
    int64_t time;
};

int SetWindow();
void Make_Task(int window2);
void Antena(hdr a);
void Print(int l, float sred);
void Print(float text);

int main()
{
    //Устанавливаем окно
    int window = SetWindow();
    //Запускаем эмуляцию крутящей антены и отправки ей сообщений
    hdr emul;
    thread th(Antena, emul);
    //Запускаем параллельно расчет скользяего среднего
    thread th2(Make_Task, window);

    //Для выхода из программы после установки окна ввести любое число, кроме 1.
    int q=1;
    while (q==1)
    {
        cin>>q;
    }
    th.detach();
    th2.detach();
    
    
    return 0;
}

//функция вывода
void Print(int l, float sred)
{
    cout << "Скользяшее среднее окна под номером: " << l << " равняется " << sred << endl;
}

//Перегрузка функции вывода
void Print(float text, float text2, int64_t text3 )
{
    cout << "Значение поворота в момент измерения: " << text << endl;
    cout << "Данные: " << text2 << endl;
    cout << "Метка времени: " << text3 << endl;
}

//функция для потока, который будет расчитывать скользяшее среднее
void Make_Task(int window2)
{
    int k = window2;
    int i = 1;
    float sr = 0;
    while (1)
    {
        if (k<vAngle.size())
        {
            {
                for (int j=i; j<i+window2; j++)
                {
                    sr = sr + vAngle[j];
                }
                sr = sr/window2;
                maAngle.push_back(sr);
                mtx.lock(); // Предполагаю, что наличие этого mutex'а может исказить метку времени. Если убрать, такого не должно произойти, но тогда в терминале в теории возникнет наложение друг на друга текста. Расчет верный, вывод местами кривой.
                Print(i,sr);
                mtx.unlock(); // Конец mutex'а.
                sr = 0;
                i=i+1;
                k=k+1;
            }
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
    
}

//Эмуляция антены
void Antena(hdr a)
{
    srand(time(NULL));
    
    while (1)
    {
        //Вывод временной метки
        a.time = duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
        vTime.push_back(a.time);
        //Рандом значение угла
        a.angle = rand()%361;
        //Рандомное
        a.data = rand()%61;
        vData.push_back(a.data);
        mtx.lock();
        vAngle.push_back(a.angle);
        Print(a.angle, a.data, a.time);
        mtx.unlock();
        
        //Задержка между отправкой сообщений
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
}

//Функция для установки размера окна
int SetWindow()
{
    int window;
    
    //Ввод окна через консоль
    cout << "Введите желаемое окно от 3 до 21: " << endl;
    cin >> window;
    //Проверка на дурака 1
    if (window<3)
    {
        cout << "Ошибка. Слишком маленькое окно. Устанавливаю окно по умолчанию на 3" << endl;
        return window = 3;
        
    }
    //Проверка на дурака 2
    if (window>21)
    {
        cout << "Ошибка. Слишком большое окно. Устанавливаю окно по умолчанию на 21" << endl;
        return window = 21;
    }
    if (window%2==0)
    {
        cout << "У окна должен быть центр. Вы вели четное. Увличиваем на 1"<< endl;
        return window = window + 1;
    }
    
    return window;
}
