#pragma once
class ArrayR {

protected:
    int* arr = nullptr;
    int arr_size = 0;  //����������� ������ �������.
    int last = 0; //   ������� �������


public:

    ArrayR(const ArrayR&) = delete;
    ArrayR& operator=(const ArrayR&) = delete;
    ArrayR();
    ArrayR(int );
    ~ArrayR();
    void add_element(int value);
    int get_element(int number);

};
