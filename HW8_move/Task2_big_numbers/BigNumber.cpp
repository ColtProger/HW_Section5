#include"BigNumber.h"

BigNumber::BigNumber(std::string aValue) {

        int start = 0;
        size = aValue.length() - 1;
        char first = aValue.at(0);
        if (first == '-') {
            isNegative = true;
            start = 1;
        }
        if (first == '0')
            throw std::runtime_error(aValue + " it's not a number!");
        for (int i = size; i >= start; i--) {
            digits.push_back(std::atoi(aValue.substr(i, 1).c_str()));
        }
    }
BigNumber::~BigNumber() {};

BigNumber:: BigNumber(BigNumber&& other) noexcept
    {
        //std::cout <<"1"<< __FUNCTION__ << std::endl;
        digits = std::move(other.digits);
        size = other.size;
        isNegative = other.isNegative;
        //other.value = nullptr;


    }

BigNumber::BigNumber(BigNumber& other) noexcept
    {
        //std::cout <<"2"<< __FUNCTION__ << std::endl;
        digits = other.digits;
        size = other.size;
        isNegative = other.isNegative;
        //other.value = nullptr;


    }

BigNumber& BigNumber::operator=(BigNumber&& other) noexcept // оператор перемещающего присваивания    
    {
        if (&other == this) return *this;

        digits = std::move(other.digits);
        size = other.size;
        isNegative = other.isNegative;
        //other.digits = nullptr;
        return *this;
    }

    BigNumber& BigNumber::operator=(BigNumber& other) noexcept // оператор перемещающего присваивания    
    {
        if (&other == this) return *this;

        digits = other.digits;
        size = other.size;
        isNegative = other.isNegative;
        //other.value = nullptr;
        return *this;
    }

    BigNumber BigNumber::operator+(const BigNumber& other) {
        BigNumber result = *this;
        int carry = 0;
        size_t length = std::max(result.digits.size(), other.digits.size());

        for (size_t i = 0; i < length || carry; ++i) {
            if (i == result.digits.size())
                result.digits.push_back(0);
            result.digits[i] += carry + (i < other.digits.size() ? other.digits[i] : 0);
            carry = result.digits[i] / 10;
            if (carry != 0)
                result.digits[i] = result.digits[i] % 10;
        }

        return result;
    }


    BigNumber BigNumber::operator*(int num) {

        BigNumber result = *this;
        int carry = 0;
        size_t length = result.digits.size();

        for (size_t i = 0; i < length || carry; ++i) {
            if (i == length)
                result.digits.push_back(0);
            result.digits[i] = carry + num * result.digits[i];
            carry = result.digits[i] / 10;
            if (carry != 0)
                result.digits[i] = result.digits[i] % 10;
        }
        return result;
    }

std::ostream& operator<<(std::ostream& os, const BigNumber& num) {
    if (num.isNegative) {
        os << "-";
    }
    for (int i = num.digits.size() - 1; i >= 0; i--) {
        os << num.digits[i];
    }

    return os;
}