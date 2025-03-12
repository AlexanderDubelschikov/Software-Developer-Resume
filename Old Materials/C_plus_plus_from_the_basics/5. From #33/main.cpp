//Функции, прототипы, область видимости {}, глобальные и локальные переменные, встраиваемая функция (inline),
//Шаблоны функций (template/class), стеки, рекурсия,

//Стеки - пример с тарелками. Последний вошел, первый вышел. Вспомни инверсию приоритетов.

#include <iostream>
#include <ctime>
using namespace std;

const char NEW_LINE = '\n';
int var,var2,var3;
double var4=1.1,var5=2.2,var6;


//Прототип функции
void privetstvie();

//Базовая функция суммирования int'ов
inline int summ(int a, int b)
{
    return a+b;
}

//Заполнить массив
void FillArray(int arr[], const int SIZE)
{
    srand(time(NULL));
    for (int i=0; i<SIZE; i++)
    {
        arr[i]=rand()%10;
    }
    
}

//Вывести массив
void PrintArray(int arr[],const int SIZE)
{
    for (int i=0; i<SIZE; i++)
    {
        cout<<arr[i]<<" ";
    }
}

//Перегрузка функций на примере суммы
int peregruz(int a, int b)
{
    return a+b;
}

double peregruz(double a, double b)
{
    return a+b;
}

int peregruz(int a, int b, int c)
{
    return a+b+c;
}

//Шаблоны функций
template<typename T1, class T2> T1 pereg(T1 a, T2 b)
{
    return a*b;
}

//Рекурсия на примере факториала (мое)
int fact(int a, int k = 1, int r = 1)
{
    if (a<k)
    {   cout<<r<<NEW_LINE;
        return 0;
    }
    
    r=r*k;
    k=++k;

    return fact(a, k, r);
}

//Рекурсия на примере факториала (грамотно)
int fact2(int a)
{
    if (a==0)
        return 0;
    
    if (a==1)
        return 1;
    
    return a*fact2(a-1);
}

//Параметры по умолчанию
void foo(int a = 5)
{
    for (int i = 0; i<a; i++)
    {
        cout << "#" << NEW_LINE;
    }
    
}

int main() {
    setlocale(LC_ALL,"Rus");
    //Приветствие
    /*privetstvie();*/

    //Использование суммы
    /*
     cin >> var;
     cin >> var2;
     var3=summ(var,var2);
     cout << var3 << NEW_LINE;*/
    
    //Массивы и функции
    /*const int SIZE = 10;
    int arr[SIZE] {};
    FillArray(arr,SIZE);
    PrintArray(arr,SIZE);
    cout << NEW_LINE;*/
    
    //Значение по умолчанию
    /*foo(3);
    cout << NEW_LINE;
    foo();*/
    
    //Перезгрузка
    /*var = peregruz(1,2);
    var4 = peregruz(1.1,2.2);
    cout << var << NEW_LINE;
    cout << var4 << NEW_LINE;
    cout << peregruz(1,2,3) << NEW_LINE;*/
    
    //Шаблоны
    /*cout << pereg(2,3) << NEW_LINE;
    cout << pereg(2.2,3) << NEW_LINE;
    cout << pereg(2,3.3) << NEW_LINE;*/
    
    //Рекурсия на примере факториала (мое)
    /*cin>>var;
    fact(var);*/
    
    //Грамотная рекурсия
    /*cin>>var;
    cout << fact2(var) << NEW_LINE;*/

    return 0;
}

//Базовая функция привествия
void privetstvie()
{
    cout << "Hello world" << NEW_LINE;
    
}

