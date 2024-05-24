#include <iostream>
#include<vector>
#include <algorithm>

template <class T>

std::vector<T> delete_dublicats(std::vector<T> vec)
{
     std::sort(vec.begin(), vec.end());  // сортировка
     auto it = std::unique(vec.begin(), vec.end());
     vec.erase(it, vec.end());

    return vec;
}



int main()
{
    std::vector<int> vec={ 1, 1, 2, 5, 6, 1, 2, 4 };

    std::vector<int> vec2 = delete_dublicats(vec);

    
    std::vector<int>::iterator it = vec2.begin(); 
    while (it != vec2.end()) 
    {
        std::cout << *it << " "; 
        it++; 
    }
}

