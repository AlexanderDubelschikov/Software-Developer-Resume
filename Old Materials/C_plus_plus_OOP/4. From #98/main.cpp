//Наследование. Модификаторы доступа. Порядок вызова конструкторов при наследовании.


#include <iostream>
#include <string>
using namespace std;

//Класс Человек
class Human
{
private:
    string name;
    string SecondName;
public:
    
    void SetSecondName(string SecondName)
    {
        this->SecondName=SecondName;
    }
    
    string GetSecondName()
    {
        return SecondName;
    }
    
    void SetName(string name)
    {
        this->name=name;
    }
    
    string GetName()
    {
        return name;
    }

};

//Класс Студент
class Student : public Human
{
public:
    string group;
    
    void Learn()
    {
        cout << "Учусь!" << endl;
    }
};

//Класс Заочник
class ExtarmularStudent : public Student
{
public:
    void Learn()
    {
        cout << "Учусь по заочному" << endl;
    }
};

//Класс Профессор
class Professor : public Human
{
public:
    string subject;
};

//Изучение модификаторов доступа
class A
{
public:
    string str = "1";
private:
    string str2 = "2";
protected:
    string str3 = "3";
};

class B : public A
{
public:
    void StrMsg()
    {
        //cout << str << endl;
        //cout << str2 << endl;
        cout << str3 << endl;
    }
    
};

//Порядок вызова конструкторов при наследовании


int main()
{
    
    //Наследование
    /*Student student1;
    student1.SetName("Иван");
    student1.group=("МИВ211");
    cout << student1.GetName() << endl;
    cout << student1.group << endl;
    student1.Learn();
    ExtarmularStudent student2;
    student2.Student::Learn();
    student2.Learn();
    student1.SetSecondName("Иванов");
    cout << student1.GetSecondName() << endl;
    student2.SetSecondName("Петров");
    cout << student2.GetSecondName() << endl;*/
    
    //Модификаторы доступа
    /*B a;
    a.StrMsg();*/
    
    //Порядок вызова конструкторов при наследовании
    
    
    return 0;
}
