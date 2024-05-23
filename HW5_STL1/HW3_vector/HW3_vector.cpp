#include <iostream>
#include <set>
#include "MyException.h"

template<class T>

class simple_vector
{
public:
  simple_vector(std::set<T> st) {
    this->actual_size = st.size();
    this->last = st.size();
    arr = new T[actual_size];
    size_t i = 0;
    for (const T& elem : st) {
        arr[i] = elem;
        if (i < (st.size() - 1)) i++;
    }
}
 ~simple_vector() {
     std::cout << __FUNCTION__ << std::endl;
     delete[] arr;
 }

void push_back(size_t value) {
    if ((last + 1) > actual_size) {
        actual_size = 2 * actual_size;
        int* new_arr = new int[actual_size];
        for (int i = 0; i < actual_size / 2; i++) {
            new_arr[i] = arr[i];
        }
        int* temp = arr;
        arr = new_arr;
        delete[] temp;
    }
    arr[last] = value;
    last++;
};

T at(int indx) const
{
    if ((indx < 0) || (indx > (actual_size - 1)) || (indx > (last - 1))) {
        throw MyException("Не корректный индекс элемента.");
    }
    else {
        return arr[indx];
    }
}
size_t  size() { return last; }

size_t capacity() { return actual_size; }

private:
    T* arr = nullptr;
    size_t actual_size = 0; // fact size
    size_t last = 0; //real size (filled)
};


int main()
{
   
    setlocale(LC_ALL, "Russian");


    simple_vector<int> sv({1,2,3});

    std::cout <<"size: "<<  sv.size() << std::endl;
    std::cout <<"capacity: "<< sv.capacity() << std::endl;

    try {
        std::cout << sv.at(3) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    sv.push_back(3);
    sv.push_back(4);


    std::cout <<"size: "<< sv.size() << std::endl;
    std::cout << "capacity: " << sv.capacity() << std::endl;

    try {
        std::cout << sv.at(3) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }


    return 0;
}


