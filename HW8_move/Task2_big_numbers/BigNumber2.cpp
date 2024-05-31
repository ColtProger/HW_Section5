#include"BigNumber2.h"

BigNumber::BigNumber()
{
	value = "0";
	size = 1;
	isNegative = false;
}

BigNumber::~BigNumber()
{
}


BigNumber::BigNumber(std::string aValue)
{
	value = aValue;
	StringToBigNum();
}

BigNumber::BigNumber(const char* aValue)
{
	std::cout << __FUNCTION__ << std::endl;
	value = aValue;
	//size = value.size() + 1;
	StringToBigNum();
}


BigNumber::BigNumber(BigNumber&& other) noexcept
{
	std::cout << __FUNCTION__ << std::endl;
	value = std::move(other.value);
	size = other.size;
	isNegative = other.isNegative;
	//other.value = nullptr;

	
}

BigNumber::BigNumber(BigNumber& other) noexcept
{
	std::cout << __FUNCTION__ << std::endl;
	value = other.value;
	size = other.size;
	isNegative = other.isNegative;
	//other.value = nullptr;


}

BigNumber& BigNumber::operator=(BigNumber&& other) noexcept // оператор перемещающего присваивания    
{        
	if (&other == this) return *this;
	
	value = std::move(other.value);
	size = other.size;
	isNegative = other.isNegative;
	//other.value = nullptr;
	return *this;    
}

BigNumber& BigNumber::operator=(BigNumber& other) noexcept // оператор перемещающего присваивания    
{
	if (&other == this) return *this;

	value = other.value;
	size = other.size;
	isNegative = other.isNegative;
	//other.value = nullptr;
	return *this;
}

void BigNumber::StringToBigNum()
{
	if (value[0] == '-') {
		value = value.erase(0, 1); // убираем знак для хранения числа
		isNegative = true;
	}
	else
		isNegative = false;
	if (value[0]  == '0')
		throw std::runtime_error(value + " it's not a number!");
	size = value.size();
	
}

std::string BigNumber::getValue()
{
	std::string value = this->value;
	if (this->isNegative)
		value.insert(0, "-");
	return value;
}



std::string BigNumber::mult(const std::string str, const int number) {
	//BigNumber result;
	std::string new_str;
	size_t size = value.size();
	//std::cout << value.size() << result.size << std::endl;
	//result.isNegative = isNegative;


	for (size_t i = 0; i < size-1; i++) {	
	    new_str[i] += value[i]; 		//number * first.value[i];
		std::cout << i << ' ' << new_str[i] << std::endl;
	}
		//std::string it = first.begin();
		//size_t i = 0;
		//for (size_t i = 0; i < value.size()-1; i++) {
		//	result.value[i] = number * value[i];
		//}
		//value  = result;
		// ;
	//result = value * 2;
	return new_str;
}

BigNumber BigNumber::multipl(int number) {
	BigNumber result;
	//std::string new_str = first.value;
	result.size = value.size();
	std::cout << value.size() << result.size << std::endl;
	result.isNegative = isNegative;


	//	for (size_t i = 0; i < result.size; i++) {
	//		
	//		new_str[i] += static_cast<char>(i); 		//number * first.value[i];
	//		std::cout << i << new_str[i] << std::endl;
	//	}
		//std::string it = first.begin();
		//size_t i = 0;
		//for (size_t i = 0; i < value.size()-1; i++) {
		//	result.value[i] = number * value[i];
		//}
		//value  = result;
		// ;
	result = mult(value, 2);
	return result;
}


//std::ostream& big_number::operator<<(std::ostream& os, big_number& value) {
//	std::string value = this->value;
//	if (this->isNegative)
//		value.insert(0, "-");
//	return value;
//}