//Массивы, генератор случайных чисел

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    const char NEW_LINE = '\n';
   
    //Инциаилизация массива и его заполнение в for
    /*const int SIZE = 10;
    int mass[size];
    int arr[10]{};
    
    for (int i = 0; i<SIZE; i++)
    {
        mass[i]=i;
    }
    
    for (int i = 0; i<10; i++)
    {
        cout << mass[i] << " ";
    }
    
    cout << NEW_LINE;
    
    for (int i = 0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << NEW_LINE;*/
    
    //sizeof
    /*const int SIZE = 10;
    int arr[SIZE];
    int i;
    
    for (i = 0; i<SIZE; i++)
    {
        arr[i]=i;
        
    }
    
    for (i=0; i<SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << NEW_LINE << sizeof (int) << NEW_LINE;
    cout << sizeof (double) << NEW_LINE;
    
    int arr2[]{11,22,33,44};
    
    for (i=0; i<sizeof(arr2)/sizeof(arr2[0]); i++)
    {
        cout << arr2[i] << " ";
    }
    
    cout << NEW_LINE;*/
    
    //random
    /*srand(time(NULL));
    
    int a = rand()%10 + 10;
    int arr[10];
    cout << a << NEW_LINE;
    
    for (int i=0; i<10; i++)
    {
        arr[i]=rand()%10 + 10;
    }
    
    for (int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout<<NEW_LINE;*/
    
    //rand without repetition in mass
    /*srand(time(NULL));
    int arr[10];
    
    for (int i=0; i<10; i++)
    {
        arr[i]=rand()%20;
        
        for (int j=0; j<i; j++)
        {
            if (arr[i]==arr[j])
            {
                arr[i]=rand()%20;
                j=0;
            }
        }
    }
    
    for (int i=0; i<10; i++)
    {
    
        cout << arr[i]<<" ";
    }
    
    cout << NEW_LINE;*/
    
    //dvumermii massiv
    /*const int ROW = 10;
    const int COL = 15;
    int d_arr[ROW][COL]{};
    int d_arr2[][3]
    {
        {1,2,3},
        {1,2,3},
        {1,2,3}
        
    };
    
    for (int i = 0; i<ROW; i++)
    {
        for (int j = 0; j<COL; j++)
            d_arr[i][j]=i;
    }
    
    for (int i = 0; i<ROW; i++)
    {
        cout << NEW_LINE;
        for (int j = 0; j<COL; j++)
            cout << d_arr[i][j] <<" ";
    }
    
    cout << NEW_LINE;
    
    for (int i = 0; i<3; i++)
    {
        cout << NEW_LINE;
        for (int j = 0; j<3; j++)
            cout << d_arr2[i][j] <<" ";
    }
    
    cout << NEW_LINE;*/
    
    
    return 0;
}

