//
//  main.cpp
//  Test 2
//
//  Created by Sokrat on 22.09.2022.

/* Имеются последовательные (по времени) измерения ориентации комплекса в пространстве: крен ( от -90 до 90 градусов), тангаж (от -90 до 90 градусов) и курс (от 0 до 360 градусов). Необходимо найти скользящее среднее и СКО каждого измеренного параметра за некоторый интервал времени.*/

#include <iostream>
#include <ctime>
#include<cmath>
using namespace std;


class UAV
{
private:
    //Основные параметры квадракоптера
    int interspace;
    int window;
    float roll;
    float pitch;
    float path;
    
    //Вспомогательные параметры для расчетов
    float *arr_roll;
    float sr_roll=0;
    
    float *arr_path;
    float sr_path=0;

    float *arr_pitch;
    float sr_pitch=0;

    //Параметры дрона в единицу времени
    void Step()
    {
        this->roll= rand()%181 - 90;
        this->pitch = rand()%181 - 90;
        this->path = rand()%361;
    
    }
    
    //Универсальный вывод массивов
    void ShowArray(float *arr)
    {
        for (int i=0; i<interspace; i++)
        {
            cout << arr[i] << "\t";
        }
        
        cout << endl;
    }
    
    //Не очень универсальня функция для шага и расчета среднего
    void Make_Sr()
    {
        for (int i=0; i<interspace; i++)
        {
            Step();
            
            arr_roll[i]=roll;
            sr_roll = sr_roll + arr_roll[i];
            
            arr_path[i]=path;
            sr_path = sr_path + arr_path[i];
            
            arr_pitch[i]=pitch;
            sr_pitch = sr_pitch + arr_pitch[i];
        }
        sr_roll = sr_roll/interspace;
        sr_path = sr_path/interspace;
        sr_pitch = sr_pitch/interspace;
    }
    
    //Универсальная функция расчета среднего скользящего
    void Make_Moving_Average(float *arr)
    {
        double sr;
        double ma;
        
        for (int i=0; i<=(interspace-window); i++)
        {
            sr=0;
            cout<<"Рассматриваем числа: ";
            
            for (int j=i; j<i+window;j++)
            {
                sr = sr + arr[j];
                cout << arr[j] << " ";
            }
            ma = sr / window;
            cout << endl << "Скольщяшее Среднее: " << ma << endl;
            cout << "====" << endl;
        
            
        }
    }
    
    //Универсальная функция для расчета среднего квадратичного отклонения
    float Make_Dis_and_SD(float *arr, float sr)
    {
        float dis = 0;
        float sd = 0;
        
        for (int i = 0; i<interspace; i++)
        {
            arr[i]=pow((arr[i]-sr),2);
            dis=dis+arr[i];
            
        }
        
        dis=dis/interspace;
        
        return sd=sqrt(dis);
    }
    
public:
    
    //Конструктор
    UAV(int interspace, int window)
    {
        roll = 0;
        pitch = 0;
        path = 0;
        this->interspace=interspace;
        if (interspace<1)
        {
            cout << "Ошибка, некорректное время наблюдения. Интервал устанавлен на дефолтное значение 2" << endl;
            this->interspace=2;
        }
        this->window=window;
        if (window<1 || window>interspace)
        {
            cout << "Ошибка, некорректное окно. Окно устаналивается на дефолтное значение 2" << endl;
            this->window=2;
        }
        arr_roll = new float [interspace];
        arr_pitch = new float [interspace];
        arr_path = new float [interspace];
    }
    
    //Деструктор
    ~UAV()
    {
        delete[] arr_roll, arr_path, arr_pitch;
    }
    
    //Единственная функция кроме контрукторов/деструкторов которая доступна. Решение поставленной задачи.
    void Make_Test_task()
    {
        Make_Sr();
        cout << "Массив roll'ов" << endl;
        ShowArray(arr_roll);
        cout << "Массив pitch'ов" << endl;
        ShowArray(arr_pitch);
        cout << "Массив path'ов" << endl;
        ShowArray(arr_path);
        cout << endl << "==========" << endl;
        
        cout << "Скользяшее среднее roll. Используя окно: " << window << endl << endl;
        Make_Moving_Average(arr_roll);
        
        cout << "==========" << endl;
        
        cout << "Скользяшее среднее path. Используя окно: " << window << endl << endl;
        Make_Moving_Average(arr_path);
       
        cout << "=========" << endl;
        
        cout << "Скользяшее среднее pitch. Используя окно: " << window << endl << endl;
        Make_Moving_Average(arr_roll);
        
        cout << "==========" << endl;
        
        cout << "Среднее квадратичное отклонение roll: " << Make_Dis_and_SD(arr_roll, sr_roll) << endl << endl;
        cout << "Среднее квадратичное отклонение pitch: " << Make_Dis_and_SD(arr_pitch, sr_pitch) << endl << endl;
        cout << "Среднее квадратичное отклонение path: " << Make_Dis_and_SD(arr_path, sr_path) << endl << endl;

        cout << "==========" << endl;
        
    }
    
};

int main()
{
    //Для рандома
    srand(time(NULL));
    
    //Создаем ивент наблюдения за дроном по времени с желаемым окном для скольщягео среднего
    UAV Number1(5,3);
    Number1.Make_Test_task();
        
    return 0;
}
