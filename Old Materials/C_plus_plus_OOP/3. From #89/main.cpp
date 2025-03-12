//Дружественные функции и классы. Определение методов вне класса. Дружественный метод класса.
//Дружественный класс. Static. Id generator. Статичкские методы. Вложенный класс. Массив объектов класса.
//Динамический. Статический. Агрегация и композиция.

#include <iostream>
#include <string>
using namespace std;

//Основной класс для работы
class MyPos
{
private:
    int x;
    int y;
    
public:
    
    MyPos(int x, int y)
    {
        this->x=x;
        this->y=y;
        cout << "Вызывался конструктор: " << this << endl;
    }
    
    MyPos()
    {
        x=0;
        y=0;
        cout << "Вызывался конструктор: " << this << endl;
    }

    bool operator == (MyPos &other)
    {
        return this->x==other.x  && this->y==other.y;
        
    }
    
    bool operator != (MyPos &other)
    {
        return this->x!=other.x || this->y!=other.y;
    }
    
    MyPos & operator = (const MyPos &other)
    {
        this->x = other.x;
        this->y = other.y;
        
        return *this;
    }
    
    MyPos operator + (const MyPos & other)
    {
        MyPos temp;
        temp.x = this -> x + other.x;
        temp.y = this -> y + other.y;
        
        return temp;

    }
    
    MyPos & operator ++ ()
    {
        this->x+=1;
        this->y+=1;
        
        return *this;
    }
    
    MyPos & operator -- ()
    {
        this->x-=1;
        this->y-=1;
        
        return *this;
    }
    
    MyPos & operator ++ (int value)
    {
        MyPos temp(*this);
        
        this->x++;
        this->y++;
        
        return temp;

    }
    
    MyPos & operator -- (int value)
    {
        MyPos temp(*this);
        
        this->x--;
        this->y--;
        
        return temp;

    }
    
    ~MyPos()
    {
        cout << "Вызывался деструктор: " << this << endl;
    }
    
    void PrintPos()
    {
        cout << x << " and " << y << endl;
    }
    
    //Блок дружественных функций
    friend void ChangeX(MyPos &value);
  
};

//Для определения методв вне класса
class MyClass
{
public:
    MyClass();
    ~MyClass();
    void PrintMSG();
    
};

//Для темы дружественные методы класса
class Human;
class Apple;

class Human
{
public:
    void TakeApple(Apple &apple);
    void EatApple(Apple &apple);
    
};

//Friend. Static. Id generator. Статический метод.
class Apple
{
public:
    
    Apple(int weight, string color)
    {
        this->weight=weight;
        this->color=color;
        this->id=count;
        Apple::count=Apple::count+1;
        
    }
    
    void PrintInfo()
    {
        cout << "Человек взял яблоко!" << endl;
        cout << "Вес: " << weight << '\t' << "Цвет: " << color << endl;
        cout << "ID: " << this->id <<endl;
    }
    
    void Kolovo()
    {
        cout << "Количество яблок равно: " << Apple::count << endl;
    }
    
    static int GetCount()
    {
        return count;
    }
    
    static void ChangeColor(Apple &apple)
    {
        apple.color="green";
    }
    
    //friend void Human::TakeApple(Apple &apple);
    friend Human;
    
private:
    int weight;
    string color;
    int id;
    static int count;
    
};

int Apple::count = 0;

//Для вложенного класса
class Image
{
public:
    void GetImageInfo()
    {
        for (int i=0; i<5; i++)
        {
            cout << pixels[i].GetInfo() << endl;
        }
    }
    
    class Pixel
    {
    public:
        
        Pixel(int r, int g, int b)
        {   this-> r = r;
            this-> g = g;
            this-> b = b;
        }
        
        string GetInfo()
        {
            return "Pixel: "+to_string(r)+"/"+to_string(g)+"/"+to_string(b);
        }
    private:
        int r;
        int g;
        int b;
    };
    
private:
    
    Pixel pixels[5]
    {
        Pixel(10,20,30),
        Pixel(11,22,33),
        Pixel(12,23,34),
        Pixel(13,14,15),
        Pixel(1,2,3)
    };
    
};

//Массив объектов класса
class Pixel
{
public:
    Pixel()
    {
        r=g=b=0;
    }
    
    Pixel(int r, int g, int b)
    {   this-> r = r;
        this-> g = g;
        this-> b = b;
    }
    
    string GetInfo()
    {
        return "Pixel: "+to_string(r)+"/"+to_string(g)+"/"+to_string(b);
    }
    
private:
    int r;
    int g;
    int b;
};

//Агрегация композиция (brain - композиция. cap - Human агрегация).
class Cap
{
public:
    string GetColor()
    {
        return color;
    }

private:
    string color = "red";
    
private:
    
};

class Human1
{
public:
    void Think()
    {
        brain.Think();
    }
    
    void CapCap()
    {
        cout<<"Цвет кепки: " << cap.GetColor() << endl;
    }
    
private:
    class Mind
    {
    public:
        void Think()
        {
            cout << "Думаю" << endl;
        }
    };
    
    Mind brain;
    Cap cap;
};

int main() {
    
    //Дружественные функции и классы
    /*MyPos a;
    a.PrintPos();
    ChangeX(a);
    a.PrintPos();*/
    
    //Определение методов вне класса
    /*MyClass a;
    a.PrintMSG();*/
    
    //Дружественный метод класса (требуется также раскомментировать строчку friend в Apple)
    /*Apple apple(2,"red");
    Human odin;
    odin.TakeApple(apple);*/
    
    //Дружественный класс
    /*Apple apple(2,"red");
    Human odin;
    odin.TakeApple(apple);
    odin.EatApple(apple);*/
    
    //Static. Id generator. Статический метод.
    /*Apple apple(20, "red");
    apple.PrintInfo();
    apple.Kolovo();
    Apple apple2(30, "red-yellow");
    apple2.PrintInfo();
    apple2.Kolovo();
    Apple apple3(30, "red-yellow");
    cout << Apple::GetCount() << endl;
    Apple::ChangeColor(apple3);
    apple3.PrintInfo();*/
    
    //Вложенный класс
    /*Image img;
    img.GetImageInfo();
    Image::Pixel pixel(3,3,3);
    cout << pixel.GetInfo() << endl;*/
    
    //Массив объектов класса
    /*const int LENGHT = 5;
    Pixel ArrPixel[LENGHT];
    for (int i=0; i<LENGHT; i++)
    {
        ArrPixel[i]=Pixel(1,2,3);
    }
    for (int i=0; i<LENGHT; i++)
    {
        cout <<ArrPixel[i].GetInfo() << endl;
    }
    
    cout << "===================" << endl;
    
    int Lenght2;
    Lenght2 = 5;
    Pixel *ArrPixel2 = new Pixel [Lenght2];
    for (int i=0; i<Lenght2; i++)
    {
        ArrPixel2[i]=Pixel(1,2,3);
    }
    for (int i=0; i<Lenght2; i++)
    {
        cout <<ArrPixel2[i].GetInfo() << endl;
    }
    delete [] ArrPixel2;*/
    
    //Агрегация и композиция
    Human1 human;
    human.Think();
    human.CapCap();
    

    
    return 0;
}

//Конструктор вне класса;
MyClass::MyClass()
{
    cout << "Конструктор" << endl;
}

//Деструктор вне класса;
MyClass::~MyClass()
{
    cout << "Деструктор" << endl;
}

//Вне класса
void MyClass::PrintMSG()
{
    cout << this << endl;
}

//Дружественная функция
void ChangeX(MyPos &value)
{
    value.x=10;
}

//Вне класса
void Human::TakeApple(Apple &apple)
{
    apple.PrintInfo();
}

void Human::EatApple(Apple &apple)
{
    cout << "Человек съел яблоко"<<endl;
    apple.PrintInfo();
}



