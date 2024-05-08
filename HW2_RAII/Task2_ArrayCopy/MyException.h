#pragma once
#include <exception>
#include <iostream>
#include <stdexcept>
#include <typeinfo>


class MyException : public std::domain_error {
public:
	MyException(const char* msg);

};

