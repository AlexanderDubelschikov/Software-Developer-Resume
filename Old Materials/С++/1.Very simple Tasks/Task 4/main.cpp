// Программа должна переводить число, введенное с клавиатуры в метрах, в километры. + case c см и мм

#include <iostream>

int main()
{   double *a = new double;
    int *b = new int;
    
    std::cout << "Введите метры: " << std::endl;
    std::cin >> *a;
    std::cout <<"Выберите режим работы: 1. км; 2.см; 3. мм" << std::endl;
    std::cin >> *b;
    
    
    switch(*b)
    {
        case(1):
            std::cout <<"В клометрах это будет:  " << *a/1000 << std::endl;
            break;
            
        case(2):
                std::cout <<"В сантиметрах это будет:  " << *a*100 << std::endl;
                break;
            
        case(3):
                std::cout <<"В миллиметрах это будет:  " << *a*1000 << std::endl;
                break;
            
        default:
            std::cout <<"Ошибка!"<< std::endl;
            break;
    }
        
        
        
    delete a;
    delete b;
}
