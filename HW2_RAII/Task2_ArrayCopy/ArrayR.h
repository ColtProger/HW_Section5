#pragma once
class ArrayR {

protected:
    int* arr = nullptr;
    int arr_size = 0;  //����������� ������ �������.
    int last = 0; //   ������� �������


public:
    ArrayR();
    ArrayR(int);
    //ArrayR(const ArrayR&);
    ~ArrayR();
    void add_element(int value);
    int get_element(int number);
    const ArrayR& operator= (const ArrayR& right);
    
};
