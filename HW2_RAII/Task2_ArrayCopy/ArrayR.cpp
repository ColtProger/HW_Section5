#include "ArrayR.h"
#include "MyException.h"
ArrayR::ArrayR() {};
ArrayR::ArrayR(int arr_size) {
    this->arr_size = arr_size;
    arr = new int[arr_size];
}

ArrayR::~ArrayR() { delete[] arr; }

void ArrayR::add_element(int value) {
    if ((last) >= arr_size) {
        throw MyException("ћассив уже заполнен!");
    }
    arr[last] = value;
    last++;
};

int ArrayR::get_element(int number) {
    if (number > arr_size) {
        throw MyException("Ќе корректный индекс элемента.");
    }
    return arr[number];

};

const ArrayR& ArrayR::operator= (const ArrayR& right) // переопредел€ю оператор присваивани€
{
   if (arr_size != right.arr_size)
        {
            delete[] arr; // освободить пространство
            arr_size = right.arr_size; // установить нужный размер массива
            arr = new int[arr_size]; // выделить пам€ть под копируемый массив
        }

        for (int i = 0; i < arr_size; i++)
            arr[i] = right.arr[i]; // скопировать массив
   
        return *this; 
}
