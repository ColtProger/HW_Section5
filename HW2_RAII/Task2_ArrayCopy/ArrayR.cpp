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
        throw MyException("������ ��� ��������!");
    }
    arr[last] = value;
    last++;
};

int ArrayR::get_element(int number) {
    if (number > arr_size) {
        throw MyException("�� ���������� ������ ��������.");
    }
    return arr[number];

};

const ArrayR& ArrayR::operator= (const ArrayR& right) // ������������� �������� ������������
{
   if (arr_size != right.arr_size)
        {
            delete[] arr; // ���������� ������������
            arr_size = right.arr_size; // ���������� ������ ������ �������
            arr = new int[arr_size]; // �������� ������ ��� ���������� ������
        }

        for (int i = 0; i < arr_size; i++)
            arr[i] = right.arr[i]; // ����������� ������
   
        return *this; 
}
