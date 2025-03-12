//Третий блок уроков, логические операции, ветвление и прочее

//Логические операции
/*
 
 < меньше
 > больше
 <= меньше или равно
 >= больше или равно
 
 ==  Равно
 != Не равно
 
 && и
 || или
 != не
 
 */

#include <iostream>
using namespace std;

int main()
{   setlocale(LC_ALL, "Rus");
    int var, var2, var3;
    const char NEW_LINE = '\n';

    
    cin >> var;
    cin >> var2;
    cin >> var3;
    
    //if и else if
    /*bool isRain = true;
    
    if (var > var2)
        cout << "Больше" <<NEW_LINE;
    else if (var < var2)
        cout << "Меньше" << NEW_LINE;
    else
        cout << "Равны" << NEW_LINE;
    
    if (var>0 && var>var2)
        cout << "Круто" <<NEW_LINE;
    else
        cout << "Не круто" << NEW_LINE;
    
    if (var3==0 || var2==0 || var==0)
        cout << "В выборке есть нули" << NEW_LINE;
    else
        cout << "В выборке нет нулей" << NEW_LINE;
    
    if (isRain)
        cout<<"Дождит"<<NEW_LINE;
    else
        cout<<"Не дождит"<<NEW_LINE;
    
    if (var % 2 == 0)
        cout<<"Четное"<<NEW_LINE;
    else
        cout<<"Не четное"<<NEW_LINE;*/
    
    //switch и break
    /*switch (var)
    {
        case 1:
            cout << var2<<NEW_LINE;
            break;
            
        case 2:
            cout << var3<<NEW_LINE;
            break;
            
        default:
            cout<<"Ты втираешь мне какую-то дичь!"<<NEW_LINE;
            
    }*/
    
    //while
    /*int i = 0;
    while (i<5)
    {
        cout<<"Хо-хо! Ха-ха!"<<NEW_LINE;
        i++;
    }*/
    
    //do while
    /*int i=20;
    do
    {cout<<"Хохо! Хаха!"<<NEW_LINE;
    } while (i<20);*/
    
    //for, break, continue
    /*for (int i = 1; ;i++)
    {
        if (i%2==1)
        {continue;}
        cout<<i<<NEW_LINE;
        if (i==10)
        {break;}
        
        
    }*/
    
    //goto
    /*cout<<"Один"<<NEW_LINE;
    
    goto link;
    
    cout<<"Два"<<NEW_LINE;
    cout<<"Три"<<NEW_LINE;
    
    link:
    
    cout<<"Четыре"<<NEW_LINE;
    cout<<"Пять"<<NEW_LINE;*/
    
    //for in for (и двумерные массивы)
    /*int a [10][10];
    for (int i=0; i<10; i++)
    {
        for (int j=0;j<10;j++)
        {
            a[i][j] = i;
        }
    }
    
    for (int i=0; i<10; i++)
    {   cout << NEW_LINE;
        for (int j=0;j<10;j++)
        {
            cout << a[i][j] << " ";
        }
    }*/
    
    return 0;
}

