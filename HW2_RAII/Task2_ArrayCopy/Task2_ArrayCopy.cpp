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

        ArrayR new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;

        for (int i = 0; i < 2; i++) {
            std::cout << arr.get_element(i) << " ";
        }

    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

}

