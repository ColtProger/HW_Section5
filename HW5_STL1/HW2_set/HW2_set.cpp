// HW2_set.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <set>


int main()
{
    std::set<int, std::greater<int>> set1;
    int length;
    std::cout << "Enter count of numbers and numbers: " << std::endl;
    std::cin >> length;

    int i = 0;
    int value;
    while(i<length) {
        std::cin >> value;
        set1.insert(value);
        i++;
    }


    for (const auto& elem : set1)    std::cout << elem << "\n";
 
    return 0;
}


