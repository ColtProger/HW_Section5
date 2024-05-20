
#include <iostream>


#include <vector>
#include <utility>

template <typename T>
class Array2d {
private:
    T** elements = nullptr; 
    size_t size_rows = 0;
    size_t size_cols = 0;
public:

 
    Array2d(size_t size_rows, size_t size_cols) {
        this ->size_rows = size_rows;
        this ->size_cols = size_cols;
        elements = new T* [size_rows];
        for (int i = 0; i < size_rows; i++) {
            elements[i] = new T[size_cols];
        }; 
    }
    ~Array2d() {
        std::cout << __FUNCTION__ << std::endl;
        for (int i = 0; i < size_rows; i++) {
            delete elements[i];
        }
        delete[]elements;
    }

    // версия для неконстантных таблиц
    T* operator [] (size_t i) {
        return elements[i];
    }

    // версия для константных таблиц
    const T* operator [] (size_t i) const {
        return elements[i];
    }

    void size() const {
          std::cout << "{" << size_rows << "," << size_cols << "}" << std::endl;
     }

};

int main()
{
    Array2d<int> arr(5,6);
    arr[1][2] = 6;
    std::cout << arr[1][2] << std::endl;;
    arr.size();

    return 0;
}

