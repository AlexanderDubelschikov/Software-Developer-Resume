//Калькулятор на стероидах

#include <iostream>
using namespace std;
const char NEW_LINE = '\n';
int ex = 1;

template<typename T1, typename T2> T1 Sum(T1 a, T2 b);
template<typename T1, typename T2> T1 Raz(T1 a, T2 b);
template<typename T1, typename T2> T1 Pro(T1 a, T2 b);
template<typename T1, typename T2> T1 Del(T1 a, T2 b);
template<typename T1> T1 Fac(T1 a);

int main()
{

    while (ex == 1)
    {   double var,var2;
        int var3;
        cout << "Выберите операцию. 1 - Сумма. 2 - Разность. 3 - Деление. 4 - Умножение. 5 - Факториал. 6 - Выход."<<NEW_LINE;
        cin>>var3;
        switch(var3)
        {
            case(1):
                cout<<"Задай число: "<<NEW_LINE;
                cin >>var;
                cout<<"Задай число: "<<NEW_LINE;
                cin >>var2;
                cout << Sum(var,var2) << NEW_LINE;
                break;
            
            case(2):
                cout<<"Задай число: "<<NEW_LINE;
                cin >>var;
                cout<<"Задай число: "<<NEW_LINE;
                cin >>var2;
                cout << Raz(var,var2) << NEW_LINE;
                break;
            
            case(3):
                cout<<"Задай число: "<<NEW_LINE;
                cin >>var;
                cout<<"Задай число: "<<NEW_LINE;
                cin >>var2;
                cout << Del(var,var2) << NEW_LINE;
                break;
            
            case(4):
                cout<<"Задай число: "<<NEW_LINE;
                cin >>var;
                cout<<"Задай число: "<<NEW_LINE;
                cin >>var2;
                cout << Pro(var,var2) << NEW_LINE;
                break;
                
            case(5):
                cout<<"Задай число: "<<NEW_LINE;
                cin >>var;
                cout << Fac(var) << NEW_LINE;
                break;
            
            case(6):
                ex = 0;
                break;
            
            default:
                cout<<"Какая-то ошибка, братан!"<<NEW_LINE;
        }
    }
    
    
    return 0;
}

template<typename T1, typename T2> T1 Sum(T1 a, T2 b)
{
    return a+b;
}

template<typename T1, typename T2> T1 Raz(T1 a, T2 b)
{
    return a-b;
}

template<typename T1, typename T2> T1 Pro(T1 a, T2 b)
{
    return a*b;
}

template<typename T1, typename T2> T1 Del(T1 a, T2 b)
{
    return a/b;
}

template<typename T1> T1 Fac(T1 a)
{
    if (a==0)
        return 0;
    
    if (a==1)
        return 1;
    
    return a*Fac(a-1);
}
