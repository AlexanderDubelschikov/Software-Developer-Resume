//ООП. Классы. Объекты классов. Экземпляр класса. Свойства классов. Методы классов. Модификаторы доступа. Геттеры и сеттеры. Показательный пример инкапсуляции на примере кофемашины. Конструктор класса. Перегрузка конструктора класса. Деструктор класса. this.

//Общая теоретическая подложка
/*Инкапсуляция
Наследование
Полиморфизм

Объекты - кофемолка и автомобиль.
===================================================================================================
Кофемолка экземпляр классак кофемолок.
У каждого объекта есть свои свойства. Например, кофемолка имеет свойство скорости вращения лезвий.
Функция, которую должна выполнять кофемолка (молоть зерна), назыаются в ООП методами.

Инкапсуляция - принцип независимости данных в ООП. Один программсит, может скрыть свойство класса,
который нужен для функциониования объекта от пользователя, оставив только доступ к нужным свойствам.
Мы можем - положить зерна, переломать зерна и достать их, но например не можем влиять на скорость вращения
шпинделя, угол наклона лезвия или иные скрытые от нас параметры.

Наследование - один объект может наследовать свойства другого объекта. Класс - кофемашины. Объект - кофемашины.
Класс кофемашины наследовать от кофемолки. Кофемашина получает метод молоть кофе и свойства кофемолки.

Полифорфизм. Объекты ведут себя по разному в зависимости от ситуации. Электрическая и ручная кофемолка. Разная
реализация, разный механизм переработки зерен, но метод один и тот же - "Молоть кофе".
===================================================================================================
Машина может ехать, тормозить и.т.д., но мы не знаем, как это все устроено на самом деле. От нас он скрыт.
Есть класс транспортное средство. Мы можем унаследовать от него легковой автомобиль, или фуры. Разные свойства,
но одинаковые методы.
===================================================================================================
Один из объектов - угольная шахта.      Другой объект - шахта добычи железной руды.
Свойство - скорость добычи.             Свойство - скорость добычи.
Метод - добывать.                       Метод - добывать.

Объект 3 - Доменная печать (уголь, железо).
Свойство - скорость производства (добычи).
Метод - плавить (производить).

Класс - постройка.
Свойство - добыча (производство).
Метод - производить.

От данного "Класса" мы "Наследуем" классы угольных шахт, железных шахт и доменны печей. Это и "наследование".
Метод один и тот же, но реализация разная. Это "полиморфизм". Каждый из них обладает скрытыми действиями, это
"инкапсуляция".
===================================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

//Класс - пользовательский тип данных.
class Human
{
    
public:
    int age;
    int weight;
    string name;
    
    void Print(int a)
    {
        cout << a << endl;
    }
    
    void Print(string a)
    {
        cout << a << endl;
    }
    
    void PrintAll()
    {
        cout << "Имя: " << "\t" << name << endl;
        cout << "Возраст: " << "\t" << age << endl;
        cout << "Вес: " << "\t" << weight << endl;
        
    }
    
    
};

//Пример из учебника
class Point
{
public:
    
    int x;
    int y;
    
    void Print()
    {
        cout << x << '\t' << y << '\t';
        PrintZ();
        
    }

protected:
    int izmerenie_4;
    
private:
    int z=10;
    
    void PrintZ()
    {
        cout << z << endl;
    }
    
    
};

//Класс Point 2 для геттеров и сеттеров, конструктора класса, перегрузки конструктора
class Point2
{
    
private:
    int x;
    int y;
    
public:
    
    //Конструкторы, this
    Point2()
    {
        x=0;
        y=0;
        cout << this << "\tconstructor" << endl;

    }
        
    Point2(int valueX, int valueY)
    {
        x=valueX;
        y=valueY;
        cout << this << "\tconstructor" << endl;
        
    }
    
    Point2(int valueX, bool flag)
    {
        if (flag)
        {
            y=10;
        }
        else
            y=0;
    }
    
    //Геттер и сеттер для X
    int GetX()
    {
        return x;
    }
    
    void SetX(int valueX)
    {
        x=valueX;
    }
    
    //Геттер и сеттер для Y
    int GetY()
    {
        return y;
    }
    
    void SetY(int y)
    {
        this->y = y;
    }
    
    //Вывод на экран
    void Print()
    {
        cout << "X: " << x<< '\t' << "Y: " << y << endl << endl;
    }
    
};

//Для примера инкапсуляции
class CoffeGrinder
{
private:
    
    int Check_Volt()
    {
        bool isVoltGood = 1;
        if (isVoltGood==true)
            return 1;
        else
            return 0;
    }
    
public:
    void Start()
    {
        /*if (Check_Volt()==1)
            cout << "Кофе-машина заработала" << endl;
        else
            cout << "Ошибка. Не устойчивое питание" << endl;*/
        
        Check_Volt()? cout << "Кофе-машина заработала" << endl : cout << "Ошибка. Не устойчивое питание" << endl;
    }
    
};

//Для изучения деструкторов
class ForDestruct
{
    int* data;
public:
    
    ForDestruct(int valueData)
    {
        
        data = new int [valueData];
        for (int i=0; i<valueData; i++)
        {
            data[i]=i;
        }
        cout << "Вызвался конструктор класса. Для объекта: " << data << endl;
    }
    
    ~ForDestruct()
    {   delete[] data;
        cout << "Вызвался деструктор. Для объекта: " << data << endl;
    }
};

void Foo();

int main()
{
    //Классы
    /*Human firstHuman;
    firstHuman.name="Alexander";
    firstHuman.age=23;
    firstHuman.weight=100;
    cout << firstHuman.name << endl;
    cout << firstHuman.age << endl;
    cout << firstHuman.weight << endl;
    
    cout << "============================" << endl;
    
    Human secondHuman;
    secondHuman.name = "Oleg";
    secondHuman.age = 23;
    secondHuman.weight = 60;
    cout << secondHuman.name << endl;
    cout << secondHuman.age << endl;
    cout << secondHuman.weight << endl;
    
    cout << "============================" << endl;
    
    Point position;
    cout << "По каким координатам расположены данные люди: " << endl;
    cout << "x: " << endl;
    cin>>position.x;
    cout << "y: " << endl;
    cin>>position.y;
    cout << "Местонахождение человеков: " << position.x << "\t" << position.y << endl;*/
    
    //Методы
    /*Human firstHuman;
    firstHuman.name="Alexander";
    firstHuman.age=23;
    firstHuman.weight=100;
    firstHuman.Print(firstHuman.name);
    firstHuman.Print(firstHuman.weight);
    firstHuman.Print(firstHuman.age);
    cout << "===============" << endl;
    firstHuman.PrintAll();*/
    
    //Модификаторы доступа
    /*Point firstPosition;
    firstPosition.x = 10;
    firstPosition.y = 10;
    firstPosition.Print();
    //firstPosition.z=10;
    //cout << firstPosition.z << endl;*/
    
    //Геттеры и сеттеры
    /*Point2 position;
    int value = 10;
    position.SetX(value);
    value = 42;
    position.SetY(value);
    position.Print();
    value = position.GetX();
    cout << value << endl;*/
    
    //Показательный пример инкапсуляции
    /*CoffeGrinder Redmond;
    Redmond.Start();*/
    
    //Конструктор класса. Перегрузка конструктора класса.
    /*Point2 position(10,10);
    position.Print();
    Point2 position2;
    position2.Print();
    Point2 position3(10,true);
    position3.Print();
    Point2 position4(10,false);
    position4.Print();*/
    
    //Деструкторы класса
    /*ForDestruct a(10);
    Foo();
    ForDestruct c(3);*/
    
    //This
    Point2 pos1;
    pos1.SetY(4);
    pos1.Print();
    Point2 pos2(2,3);
    pos2.Print();
    


    return 0;
}

//Функция для деструктора
void Foo()
{
    cout <<"Начало Foo" << endl;
    ForDestruct b(5);
    cout <<"Конец Foo" << endl;
    
    
}
