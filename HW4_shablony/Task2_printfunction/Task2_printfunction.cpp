﻿// Task2_printfunction.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>
#include<set>
#include<list>
#include<vector>


template <typename Containter>
void print_container(Containter& cont)
{
    for (auto i : cont)
       std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set); // four one three two.


    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list); // one two three four

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector); // one two three four
}
