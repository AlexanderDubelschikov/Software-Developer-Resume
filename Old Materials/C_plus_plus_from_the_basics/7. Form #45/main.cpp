//Статическое и динамическое выделение памяти, указатели, арифметика указателей, ссылки

#include <iostream>
using namespace std;
const char NEW_LINE = '\n';

void Foo(int *pa, int *pb);
void Foo2(int *pa, int *pb);
void Foo3(int &aRef);
void Foo4(int *pa);
void Foo5(int &aRef, int &bRef);
template <class T1, class T2> void Foo6(T1 &aRef, T2 &bRef);

int main()
{
    //Базовое знакомство с указателями
    /*int a=10;
    cout << a << NEW_LINE;
    int *pa = &a;
    cout << pa << NEW_LINE;
    cout << *pa << NEW_LINE;
    int *pa2 = &a;
    cout << *pa2 << NEW_LINE;
    *pa2 = 2;
    cout << *pa << NEW_LINE;*/
    
    //Указатели массивов и арифметика указателей
    /*const int SIZE = 5;
    int arr[5]{1,2,3,4,5};
    
    for (int i=0; i<SIZE; i++)
    {
        cout<<arr[i]<<" \t";
    }
    cout<<NEW_LINE;
    cout<<"============================="<< NEW_LINE;
    int *pArr = arr;
    cout<<"arr:\t"<<arr<<NEW_LINE;
    cout<<"pArr:\t"<<pArr<<NEW_LINE;
    cout<<"=============================" << NEW_LINE;
    for (int i=0; i<SIZE; i++)
    {
        cout<<*(pArr+i)<<" \t";
    }
    cout<<NEW_LINE;*/
    
    //Параметры в функцию по указателю
    /*int a = 55;
    int b = 66;
    cout<<a<<NEW_LINE;
    cout<<b<<NEW_LINE;
    Foo(&a,&b);
    cout<<a<<NEW_LINE;
    cout<<b<<NEW_LINE;
    Foo2(&a,&b);
    cout<<a<<NEW_LINE;
    cout<<b<<NEW_LINE;*/
    
    //Ссылки
    /*int a = 5;
    int *pa = &a;
    int &aRef = a;
    
    cout << pa << "\t" << aRef << NEW_LINE;
    aRef = 66;
    cout << a << NEW_LINE;*/
    
    //Ссылки в функцию
    /*int a = 10;
    cout << a << NEW_LINE;
    Foo3(a);
    cout << a << NEW_LINE;
    Foo4(&a);
    cout << a << NEW_LINE;*/
    
    //Несколько значений по ссылке и смена местами
    /*int a = 10, b = 30;
    cout << a << "\t" << b << NEW_LINE;
    Foo5(a,b);
    cout << a << "\t" << b << NEW_LINE;
    Foo6(a,b);
    cout << a << "\t" << b << NEW_LINE;*/
    
    //Модификация
    int c;
    cout << "Double - 1; Integer - 2" << NEW_LINE;
    cin >> c;
    switch(c)
    {
        case (1):
            double var1,var2;
            cout << "Введи два числа" << NEW_LINE;
            cin >> var1;
            cin >> var2;
            cout << var1 << "\t" << var2 << NEW_LINE;
            Foo6(var1,var2);
            cout << var1 << "\t" << var2 << NEW_LINE;
            break;
            
            
        case (2):
            int var3,var4;
            cout << "Введи два числа" << NEW_LINE;
            cin >> var3;
            cin >> var4;
            cout << var3 << "\t" << var4 << NEW_LINE;
            Foo6(var3,var4);
            cout << var3 << "\t" << var4 << NEW_LINE;
            break;
            
        default:
            cout << "Ты втираешь мне какую-то дичь!" << NEW_LINE;
            
        
    }
    
    return 0;
}

//Параметры в функцию по указателю
void Foo(int *pa, int *pb)
{
    (*pa)++;
    (*pb)--;
}

//Функция для свапа переменных местами
void Foo2(int *pa, int *pb)
{
    int c = (*pa);
    (*pa) = (*pb);
    (*pb) = c;
}

//Функция по ссылке
void Foo3(int &aRef)
{
    aRef=aRef+1;
}

void Foo4(int *pa)
{
    (*pa)++;
}

//Несколько переменных по ссылке
void Foo5(int &aRef, int &bRef)
{
    aRef-=10;
    bRef+=10;
}

//Функция для свапа переменных местами по ссылкам
template <class T1, class T2>
void Foo6(T1 &aRef, T2 &bRef)
{
    T1 c = aRef;
    aRef = bRef;
    bRef = c;
}
