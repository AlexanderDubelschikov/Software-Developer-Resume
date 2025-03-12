//Определить класс Children, который содержит такие поля (члены класса): закрытые – имя ребенка,
//фамилию и возраст , публичные – методы ввода данных и отображения их на экран. Объявить два
//объекта класса, внести данные и показать их.

#include <iostream>
#include <string>
using namespace std;

class Children
{
private:
    string name, fullname;
    int age;
    
public:
    Children(string name, string fullname, int age)
    {
        this -> name = name;
        this -> fullname = fullname;
        this -> age = age;
    }
    
    void Show();
    
};

int main()
{
    Children one("Vasilii","Pupkin",13);
    Children two("Peter","Pervii",8);
    one.Show();
    two.Show();

}

void Children::Show()
{
    cout << "Name: " << name << endl;
    cout << "FullName: " << fullname << endl;
    cout << "Age: " << age << endl;
    cout << "===========" << endl;
}
