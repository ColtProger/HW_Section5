#include <iostream>
#include<vector>

template <class T> 
T square(T a) {
    return a * a;
} 

template <typename T>
std::vector<T> square(std::vector<T> a)
{ 
   std::vector<T> b;

   for (int i=0; i<a.size(); i++) 
       {
          b.push_back(a[i]* a[i]);
        }

    return b; 
}
int main()
{
    std::vector<double> vec{ 1.0, 10.5,7.3,-9.0,4.1 };
    std::vector<double> vec2 = square(vec);
    for (int i = 0; i < vec2.size(); i++)
    {
       std::cout << vec2[i] << " ";
    }

    std::cout << std::endl;
    std::cout << square(2.34);
}

