#include "ArrayR.h"
#include "MyException.h"
ArrayR::ArrayR() {};
ArrayR::ArrayR(int arr_size) {
    this->arr_size = arr_size;
    arr = new int[arr_size];
}

 ArrayR::~ArrayR() { delete[] arr; }

 ArrayR::ArrayR(ArrayR& arrayToCopy) // ����������� �����
 {
     arr_size = arrayToCopy.arr_size; // ���������� ������ ������ �������
     last = arrayToCopy.last;
     arr = new int[arr_size]; // �������� ����� � ������ ��� �������

    for (int i = 0; i < arr_size; i++) {
        arr[i] = arrayToCopy.arr[i]; // ��������� ������ ���������� ������� arrayToCopy
    }
}


void ArrayR::add_element(int value) {
    if ((last) >= arr_size) {
        throw MyException("������ ��� ��������!");
    }
    arr[last] = value;
    last++;
};

int ArrayR::get_element(int number) {
    if ((number < 0) || (number > (arr_size - 1)) || (number > (last - 1))) {
        throw MyException("�� ���������� ������ ��������.");
    }
    return arr[number];

};

 ArrayR& ArrayR::operator= (const ArrayR& right) // ������������� �������� ������������
{
     if (this == &right)                 //���� ����������������
         return *this;
    
     delete[] arr; // ���������� ������������
     arr_size = right.arr_size; // ���������� ������ ������ �������
     last = right.last;
     arr = new int[arr_size]; // �������� ������ ��� ���������� ������
        

        for (int i = 0; i < arr_size; i++)
            arr[i] = right.arr[i]; // ����������� ������
   
        return *this; 
}
