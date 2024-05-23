#include "MyException.h"

MyException::MyException(const char* msg) :std::domain_error(msg)
{
};