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
            throw MyException("Массив уже заполнен!");
        }
        arr[last] = value;
        last++;
    };

  int ArrayR::get_element(int number) {
        if (number > arr_size) {
            throw MyException("Не корректный индекс элемента.");
        }
        return arr[number];

    };
