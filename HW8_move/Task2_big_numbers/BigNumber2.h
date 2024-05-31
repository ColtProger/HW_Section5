#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>

//By default, it is initialized to 0. It can accept either a string or long long int.
class BigNumber {
private:
	std::string value;
	size_t size;
	bool isNegative;
	
public:
	BigNumber();
	~BigNumber();
	

	BigNumber(std::string aValue);

	BigNumber(const char* const aValue);

	void StringToBigNum();

	BigNumber(BigNumber&& other) noexcept;
	
	BigNumber& operator=(BigNumber&& other) noexcept;

	BigNumber(BigNumber& other) noexcept;
	

	BigNumber& operator=(BigNumber& other) noexcept;

	BigNumber multipl(int number);
	
	//big_number(const char* other_value);
	//~big_number();

	//big_number(std::string other_value);
	//@return string
	std::string getValue();
	std::string mult(const std::string str, const int number);

	//std::ostream& operator<<(std::ostream& os, big_number& num);
	//std::ostream& operator<<(big_number& num)
};
