/* Андрей работает в секретной химической лаборатории, в которой производят опасную кислоту с удивительными свойствами. У Андрея есть
n бесконечно больших резервуаров, расположенных в один ряд. Изначально в каждом резервуаре находится некоторое количество кислоты. Начальство Андрея требует, чтобы во всех резервуара содержался одинаковый объем кислоты. К сожалению, разливающий аппарат несовершенен. За одну операцию он способен разлить по одному литру кислоты в каждый из первых
k(1≤k≤n) резервуаров. Обратите внимание, что для разных операций k могут быть разными. Поскольку кислота очень дорогая, Андрею не разрешается выливать кислоту из резервуаров. Андрей просит вас узнать, можно ли уравнять объемы кислоты в резервуарах, и, если это возможно, то посчитать минимальное количество операций, которое потребуется, чтобы этого достичь.
*/

#include <iostream>

int main()
{   //Кол-во резервуаров
    int k;
    int c=0;
    int r=0;
    std::cin >> k;
    
    //Забиваем массив
    int *n = new int[k];
    for (int i = 0; i < k; i++) {
        std::cin >> n[i];
    }
    
    //Гоняем массив
    for (int i = 0; i < k-1; i++)
    {
        if(n[i+1]<n[i])
        {
            c=10;
            break;
        }
        
        if(n[i+1]>n[i])
        {
            r=r + (n[i+1]-n[i]);
            
        }
        
    }
    
    // Вывод ответа
    if (c>1)
        std::cout << -1 << std::endl;
    else if (k==1)
        std::cout << 0 << std::endl;
    else
        std::cout << r << std::endl;
}
