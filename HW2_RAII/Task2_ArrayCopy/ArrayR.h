#pragma once
class ArrayR {

protected:
    int* arr = nullptr;
    int arr_size = 0;  //‘актический размер массива.
    int last = 0; //   позици€ курсора


public:

    ArrayR();
    ArrayR(int);
    ArrayR(ArrayR&);
    ~ArrayR();
    void add_element(int value);
    int get_element(int number);
    ArrayR& operator= (const ArrayR& right);
    
};
