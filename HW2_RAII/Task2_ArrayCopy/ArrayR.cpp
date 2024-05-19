#include "ArrayR.h"
#include "MyException.h"
ArrayR::ArrayR() {};
ArrayR::ArrayR(int arr_size) {
    this->arr_size = arr_size;
    arr = new int[arr_size];
}

 ArrayR::~ArrayR() { delete[] arr; }

 ArrayR::ArrayR(ArrayR& arrayToCopy) // конструктор копии
 {
     arr_size = arrayToCopy.arr_size; // установить нужный размер массива
     last = arrayToCopy.last;
     arr = new int[arr_size]; // выделить место в памяти для массива

    for (int i = 0; i < arr_size; i++) {
        arr[i] = arrayToCopy.arr[i]; // заполняем массив значениями массива arrayToCopy
    }
}


void ArrayR::add_element(int value) {
    if ((last) >= arr_size) {
        throw MyException("Массив уже заполнен!");
    }
    arr[last] = value;
    last++;
};

int ArrayR::get_element(int number) {
    if ((number < 0) || (number > (arr_size - 1)) || (number > (last - 1))) {
        throw MyException("Не корректный индекс элемента.");
    }
    return arr[number];

};

 ArrayR& ArrayR::operator= (const ArrayR& right) // переопределяю оператор присваивания
{
     if (this == &right)                 //если самоприсваивание
         return *this;
    
     delete[] arr; // освободить пространство
     arr_size = right.arr_size; // установить нужный размер массива
     last = right.last;
     arr = new int[arr_size]; // выделить память под копируемый массив
        

        for (int i = 0; i < arr_size; i++)
            arr[i] = right.arr[i]; // скопировать массив
   
        return *this; 
}
