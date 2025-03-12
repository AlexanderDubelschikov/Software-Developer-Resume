//
//  main.cpp
//  Test 3
//
//  Created by Sokrat on 23.09.2022.
//
//  Задание с парсингом

#include <iostream>
#include <vector>
//Библиотека для динамической типизации
#include <boost/variant.hpp>
#include <string>
using namespace std;

//Структура для одного сообщения
struct hdr
{
    uint32_t time1;
    uint32_t time2;
    uint32_t id;
    uint8_t status;
    uint8_t size;
    uint8_t type;
    uint8_t reserv;
    boost::variant<float, string, uint32_t, uint8_t> massage;
};

void Step(hdr First, vector <hdr> &Pars, int &i, char str[]);
void ShowAll (vector <hdr> Pars);
uint32_t Bit32(int &i, char str[]);
uint8_t Bit8 (int &i, char str[]);
boost::variant<float, string, uint32_t, uint8_t> MakeMassage(uint8_t size, uint8_t type, int &i, char str[]);

int main()
{
    int i = 0;
    vector <hdr> Pars;
    hdr First;
    
    //Сюда можно добовлять новые сообщения. char buff из условия.
    char str[] = "21242001000126001111111122200200021310Ura3355200800030320333476520100004313011122200200053390Ura2211220000069510Konec";

    //Парсинг
    while (str[i]!='\0')
    {
        Step(First, Pars, i, str);
    }
    
    //Отобразить все структуры из массива (вектора)
    ShowAll(Pars);
    
    return 0;
}

//Один шаг парсинга
void Step(hdr First, vector <hdr> &Pars, int &i, char str[])
{
    First.time1 = Bit32(i,str);
    First.time2 = Bit32(i, str);
    First.id = Bit32(i, str);
    First.status = Bit8(i, str);
    First.size = Bit8(i, str);
    First.type = Bit8(i, str);
    First.reserv = Bit8(i, str);
    First.massage = MakeMassage(First.size, First.type, i, str);
    
    Pars.push_back(First);
    
}

//Показать все сообщения
void ShowAll (vector <hdr> Pars)
{
    for(auto var : Pars)
    {
        cout << "Время нижние байты: " << var.time1 << endl;
        cout << "Время верхние байты: " << var.time2 << endl;
        cout << "ID: " << var.id << endl;
        var.status>4? cout << "Ошибка, некорректное состояние. Ошибка." << endl : cout << "Состояние: " << unsigned(var.status) << endl;
        cout << "Размер: " << unsigned(var.size) << endl;
        cout << "Тип: " << unsigned(var.type) << endl;
        cout << "Рзерв: " << unsigned(var.reserv) << endl;
        if (var.type==3)
        {
            uint8_t msg = boost::get<uint8_t>(var.massage);
            cout << "Сообщение: " << unsigned(msg) << endl;
        }
        else
            cout << "Сообщение: " << var.massage << endl;
        cout << "================" << endl;
    }
}

//Шаг в 32 бит
uint32_t Bit32(int &i, char str[])
{
    int j = i;
    char char_array[4];
    int k=0;
    for (i; i<j+4; i++)
    {
        char_array[k]=str[i];
        k=k+1;
    }
    uint32_t bit = (uint32_t)atoi(char_array);
    return bit;
}

//Шаг в 8 бит
uint8_t Bit8 (int &i, char str[])
{
    char char_array[1];
    char_array[0]=str[i];
    uint8_t bit = (uint8_t)atoi(char_array);
    i++;
    return bit;
}

//Создание сообщения, определение типа сообщения
boost::variant<float, string, uint32_t, uint8_t> MakeMassage(uint8_t size, uint8_t type, int &i, char str[])
{
    boost::variant<float, string, uint32_t, uint8_t> bit;
    int j = i;
    char char_array[size];
    int k=0;
    for (i; i<j+size; i++)
    {
        char_array[k]=str[i];
        k=k+1;
    }
    
    switch (type) {
        case 0:
            bit = (float)atoi(char_array);
            break;
        case 1:
            bit = string(char_array);
            break;
        case 2:
            bit = (uint32_t)atoi(char_array);
            break;
        case 3:
            bit = (uint8_t)atoi(char_array);
            break;
        //Защита, если укажут не существующий тип
        default:
            string error = "Error type";
            bit = error;
            break;
    }
    return bit;
}
