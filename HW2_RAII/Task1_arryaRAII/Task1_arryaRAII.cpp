#include <iostream>
#include "MyException.h"
#include "ArrayR.h"



int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        ArrayR arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(2) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    
}

