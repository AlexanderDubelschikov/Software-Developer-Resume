//Указатели на функцию. Прероцессор. #define. Макросы функци. Услованя компиляция. Тернарный оператор. argc argv.

#include <iostream>
#include <string>
#define PI 3.14
#define TAB '\t'
#define NEW_LINE '\n'
#define begin {
#define end }
#define Foo(x,y) ((x)*(y))
//#define DEB
#define DEBUG 0


using namespace std;

int Foo1(int var);
int Foo2(int var);
void ShowInfo(string (*foo)());
string GetDataFromDB();
string GetDataFromWebServer();

int main(int argc, const char * argv[]) {

    //Знакомтсво с указателями на функцию 1
    /*int(*fooPointer)(int var);
    int var = 2;
    int k=0;
    cout << "1 -; 2 +;" << endl;
    cin >> k;
    
    if (k==1)
    {
    fooPointer=Foo1;
    cout << fooPointer(var) << endl;
    }
    
    if (k==2)
    {
    fooPointer=Foo2;
    cout << fooPointer(var) << endl;
    }*/
    
    //Знакомтсво с указателями на функцию 2 (важно)
    /*ShowInfo(GetDataFromDB);
    ShowInfo(GetDataFromWebServer);*/
    
    //#define и макросы функций
    /*cout << PI << endl;
    cout << "text" << TAB << "text" << NEW_LINE;
    cout << "text" << TAB << "text" << NEW_LINE;
    for (int i = 0; i<5; i++)
    begin
        cout << i << NEW_LINE;
    end
    cout << Foo(5,5) << NEW_LINE;*/
    
    //Условная компиляция
    /*#ifdef DEB
        cout << "==============" << NEW_LINE;
    #else
        cout << "Дебаг выключен" << NEW_LINE;
    #endif //DEB
    for(int i=0; i<5; i++)
    {
        cout << "Ho-Ho" << TAB << "Ha-ha" << NEW_LINE;
    }
    #if DEBUG
        cout << "==============" << NEW_LINE;
    #endif //DEBUG*/
    
    //Тернарный оператор
    /*int a = 5;
    int b = 5;
    a++; //Унарный
    a = a+b; //Бинарный
    int c;
    cin >> c;
    (c<10) ? (cout << "Меньше десяти"<< endl) : (c>10) ? (cout << "Больше десяти"<< endl) : (cout << "Равно десяти"<< endl);//Тернарный*/
    
    //argc argv
    /*for (int i=0; i<argc; i++)
    {
        cout << argv[i] << endl;
    }*/
    
    
    return 0;
}

//Тестовая функция 1
int Foo1(int var)
{
    return var-1;
}

//Тестовая функция 2
int Foo2(int var)
{
    return var+1;
}

//Показать инфу
void ShowInfo(string (*foo)())
{
    cout << foo() << endl;
}

//Якобы передать данные из БД
string GetDataFromDB()
{
    return "DataFromDB";
}

//Якобы передать данные с веб сервера
string GetDataFromWebServer()
{
    return "DataFromWebServer";
}
