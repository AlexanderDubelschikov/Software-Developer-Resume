//Создать класс Tiles (кафель), который будет содержать поля с открытым доступом: brand, size_h,
//size_w, price и метод класса getData(). В главной функции объявить пару объектов класса и внести
//данные в поля. Затем отобразить их, вызвав метод getData().

#include <iostream>
#include <string>
using namespace std;

class Tiles
{
public:
    string brand;
    int size_h, size_w, price;
    
    Tiles(string brand, int size_h, int size_w, int price)
    {
        this -> brand = brand;
        this -> size_h = size_h;
        this -> size_w = size_w;
        this -> price = price;
    }
    
    void GetData();
    
};

int main()
{
    Tiles tiles1("One", 20, 20, 20);
    Tiles tiles2("Two", 30, 30, 30);
    Tiles tiles3("Three", 40, 40, 40);
    tiles1.GetData();
    cout << "===========" << endl;
    tiles2.GetData();
    cout << "===========" << endl;
    tiles3.GetData();
    cout << "===========" << endl;
    

}

void Tiles::GetData()
{
    cout << "Brand: " << brand << endl;
    cout << "Size_h: " << size_h << endl;
    cout << "Size_w: " << size_w << endl;
    cout << "Price: " << price << endl;
}
