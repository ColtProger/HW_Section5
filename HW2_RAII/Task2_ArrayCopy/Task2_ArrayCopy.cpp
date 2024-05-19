#include <iostream>
#include "MyException.h"
#include "ArrayR.h"



int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        ArrayR arr(5);
        arr.add_element(10);
        arr.add_element(20);
        //arr.add_element(155);

        ArrayR new_array(5);
       // new_array.add_element(44);
        //new_array.add_element(34);

       new_array=arr;

       // arr.add_element(23);

       // ArrayR arr3(arr);

        std::cout << new_array.get_element(1) << std::endl;

       // for (int i = 0; i < 2; i++) {
        //    std::cout << new_array.get_element(i) << " ";
        //}

    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

}

