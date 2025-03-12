//Конструктор копирования. Перегрузка оператора присваивания. Перегрузка равно и не равно. Перегрузка оператора сложения. Перегрузка инкремента и дикремента. Перегрузка [].

#include <iostream>
using namespace  std;

//Конструктор копирования. Оператор присваивания.
class MyClass
{
private:
    int *data;
    int size;
    
public:
    //Конструктор
    MyClass(int size)
    {
        this->size = size;
        this->data = new int [size];
        for (int i=0; i<size; i++)
        {
            data[i]=i;
        }
        cout << "Конструктор\t" << this << endl;
    }
    
    //Конструктор копирования
    MyClass(const MyClass &other)
    {
        this->size = other.size;
        this->data = new int[other.size];
        for (int i=0; i<other.size; i++)
        {
            this->data[i]=other.data[i];
        }
        cout << "Конструктор копирования\t" << this << endl;
    }
    
    //Оператор присваивания
    MyClass & operator = (const MyClass &other)
    {
        if (this->data!=nullptr)
        {
        delete [] this->data;
        }
        this->size = other.size;
        this->data = new int[other.size];
        for (int i=0; i<other.size; i++)
        {
            this->data[i]=other.data[i];
        }
        cout << "Вызвался оператор присваивания\t" << this << endl;
        return *this;
        
    }
    
    
    //Деструктор
    ~MyClass()
    {   delete [] data;
        cout << "Деструктор\t" << this << endl;
    }
    
};

//Перегрузка равно и не равно
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
    }

    //Опреатор равенства
    bool operator == (MyPos &other)
    {
        return this->x==other.x  && this->y==other.y;
        
    }
    
    //Оператор не равенства
    bool operator != (MyPos &other)
    {
        return this->x!=other.x || this->y!=other.y;
    }
    
    //Присваивание
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
    
    //Префиксная форма
    MyPos & operator ++ ()
    {
        this->x+=1;
        this->y+=1;
        
        return *this;
    }
    
    //Префиксная форма
    MyPos & operator -- ()
    {
        this->x-=1;
        this->y-=1;
        
        return *this;
    }
    
    //Постфиксная форма
    MyPos & operator ++ (int value)
    {
        MyPos temp(*this);
        
        this->x++;
        this->y++;
        
        return temp;

    }
    
    //Постфиксная форма
    MyPos & operator -- (int value)
    {
        MyPos temp(*this);
        
        this->x--;
        this->y--;
        
        return temp;

    }
    
    //Постфиксная форма

    ~MyPos()
    {
        cout << "Вызывался деструктор: " << this << endl;
    }
    
    void PrintPos()
    {
        cout << x << " and " << y << endl;
    }
  
};

//Перегрузка []
class TestClass
{
private:
    int Array[5]{55,44,33,22,11};

public:
    
    int & operator [] (int index)
    {
        return Array[index];
    }
    
    void Print()
    {
        for (int i=0; i<5; i++)
        {
            cout << this->Array[i] << endl;
        }
    }
    
};


void Foo(MyClass value);
MyClass Foo2();


int main()
{
    //Изучение конструктора копирования
    /*//Foo(a);
    //Foo2();
    MyClass a(5);
    MyClass b(a);*/
    
    //Перегрузка оператора присваивания
    /*MyClass a(5);
    MyClass b(10);
    MyClass c(5);
    //MyClass b = a; //Вызовется не присваивание, а конструктор копирования, т.к. b не создано!
    c=a=b;
    //a.operator=(b);//Эквивалент a=b;*/

    //Перегрузка равно и не равно
    /*MyPos position1(0, 0);
    position1.PrintPos();
    MyPos position2;
    position2.PrintPos();
    cout <<"===================="<<endl;
    position1==position2? cout << "Они равны!" << endl : cout << "Они не равны!" << endl;
    cout <<"===================="<<endl;
    position1!=position2? cout << "Они не равны!" << endl : cout << "Они равны!" << endl;
    cout <<"===================="<<endl;*/
    
    //Перегрузка оператора сложения
    /*MyPos a(10, 2);
    MyPos b(11, 3);
    MyPos c;
    a=b;
    a==b? cout << "+" << endl : cout << "-" << endl;
    c=a+b;
    c.PrintPos();*/
    
    //Перегрузка инкремента и дикремента
    /*MyPos position;
    position.PrintPos();
    ++position;
    position.PrintPos();
    --position;
    position.PrintPos();
    position++;
    position.PrintPos();
    position--;
    position.PrintPos();
    MyPos position2 = position++;
    position2.PrintPos();*/
    
    //Перегрузка []
    /*TestClass a;
    a.Print();
    cout << "========" << endl;
    cout << a[0] << endl;
    cout << a[4] << endl;*/
    

    return 0;
}

void Foo(MyClass value)
{
    cout << "Вызвалась функция Foo" << endl;
}

MyClass Foo2()
{
    cout << "Вызвалась функция Foo2" << endl;
    MyClass temp(2);
    return temp;
}
