#include <iostream>
using namespace std;

const char NEW_LINE = '\n';
const char TAB = '\t';

void FillArray(int* const arr, const int size);
void ShowArray(const int* const arr, const int size);
void Sort_Array(int* arr, const int size);
void Check(int* arr, const int size, const int index);
void All_Check(int* arr, const int size);
void Copy_Array(int* arr, int* arr2, const int size);


int main(int argc, const char * argv[])
{
    int const size = 3;
    int arr[size];
    FillArray(arr, size);
    Check(arr,size,0);
    Check(arr,size,1);
    Check(arr,size,2);
    
}

//Заполнение массива
void FillArray(int* const arr, const int size)
{
    for (int i = 0; i<size; i++)
    {
        cin >> arr[i];
    }
}

//Использовалась для проверок
void ShowArray(const int* const arr, const int size)
{
    for (int i = 0; i<size; i++)
    {
        cout << arr[i] << TAB;
    }
    
    cout << NEW_LINE;
}

//Сортировка
void Sort_Array(int* arr, const int size)
{   int sup;
    int i = 0;
    if (arr[i]>arr[i+1])
    {
        sup = arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=sup;
    }
    
    if (arr[i+1]>arr[i+2])
    {
        int sup = arr[i+1];
        arr[i+1]=arr[i+2];
        arr[i+2]=sup;
    }
    
    if (arr[i]>arr[i+1])
    {
        int sup = arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=sup;
    }
    
}

//Копирование массивов
void Copy_Array(int* arr, int* arr2, const int size)
{
    for (int i=0; i<3; i++)
    {
        arr2[i]=arr[i];
    }
}

//Проверка
void Check(int* arr, const int size, const int indx)
{   int sup;
    int arr2[3];
    int k=0, g=0;
    Copy_Array(arr, arr2, size);
    //cout << "====="<< NEW_LINE;
    sup = arr2[indx];
    //cout << sup << NEW_LINE;
    Sort_Array(arr2,size);
    //ShowArray(arr2, size);
    if (sup==arr2[1])
    {
        k=1;
        g=1;
    }
    //cout << "====="<< NEW_LINE;
    
    if(g==0)
    {
        for (int i = 0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                if (i!=j && k!=1)
                {
                    Copy_Array(arr,arr2,size);
                    arr2[i]=arr2[i]-arr[j];
                    sup = arr2[indx];
                    //cout << sup << NEW_LINE;
                    Sort_Array(arr2,size);
                    //ShowArray(arr2, size);
                    if (sup==arr2[1])
                    {
                        k=1;
                    }
                    //cout <<k << NEW_LINE;
                    //cout << "===========" << NEW_LINE;
                    
                }
            }
        }
    }

    if (k==1)
    {cout << "YES" << NEW_LINE;}
    else
    {cout << "NO" << NEW_LINE;}
            
}




