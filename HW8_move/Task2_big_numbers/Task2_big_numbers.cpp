#include <iostream>
#include<string>
#include<cstring>
#include<vector>
#include"BigNumber.h"
//class big_number {
//private:
//    char* cstring = nullptr; // сырой указатель
//    std::size_t s_length = 0;
//    int sign;
//public:
//    big_number(const char* const astring) {
//
//        std::cout << __FUNCTION__ << std::endl;
//        s_length = std::strlen(astring) + 1;
//
//        char* cstring = new char[s_length];
//
//        strcpy_s(cstring, s_length, astring);
//    };
//
//
//    ~big_number() // деструктор    
//    {
//        std::cout << __FUNCTION__ << std::endl;
//        delete[] cstring;
//    }
//
//    big_number(const big_number& other) : big_number(other.cstring) { // конструктор копирования
//        std::cout << __FUNCTION__ << std::endl;
//        char*  cstring = new char[other.s_length];
//        strcpy_s(cstring, s_length, other.cstring);
//        s_length = other.s_length;
//
//    }
//
//    big_number(big_number&& other) noexcept { // конструктор перемещения 
//        std::cout << __FUNCTION__ << std::endl;
//        cstring = other.cstring;
//        other.cstring = nullptr;
//        s_length = other.s_length;
//    }
//
//    big_number& operator=(const big_number& other) { // оператор копирующего присваивания  
//        std::cout << __FUNCTION__ << std::endl;
//        if (&other == this) return *this;
//        if (nullptr != cstring) delete[] cstring;
//
//        cstring = new char[other.s_length];
//        strcpy_s(cstring , s_length, other.cstring);
//        s_length = other.s_length;
//        return *this;
//    }
//
//    big_number& operator=(big_number&& other) noexcept{// оператор перемещающего присваивания 
//        std::cout << __FUNCTION__ << std::endl;
//        if (&other == this) return *this;
//
//        cstring = other.cstring;
//        other.cstring = nullptr;
//        s_length = other.s_length;
//
//        return *this;
//    }
//
//
//    /*big_number operator+(big_number other)
//    {
//        if (s_length > other.s_length) {
//          
//        }
//        int numerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
//        int denominator = denominator_ * other.denominator_;
//        return Fraction(numerator, denominator).reduction();
//    }*/
//
//   /* friend std::ostream& operator<<(std::ostream& left, big_number right) {
//        for (auto i: right) {
//            return std::cout <<i << " ";
//        }
//    }*/
//
//    std::ostream& operator<<(std::ostream& os, big_number& num) {
//        num._normalizationSigns();
//        if (num.sign == -1) {
//            os << '-';
//        }
//        os << num.chunks[num.chunks.size() - 1];
//        for (int i = num.chunks.size() - 2; i >= 0; i--) {
//            os << setw(num.getBASE()) << setfill('0') << num.chunks[i];
//        }
//        return os;
//    }
//
//
//
//};

int main()
{
	auto number1 = BigNumber("114575");
	auto number2 = BigNumber("78524");
	auto result = number1 + number2;
	std::cout << "sum: " << result << std::endl; // 193099

	auto result2 = number1 * 2;
	std::cout << "multipl: " << result2 << std::endl; // 229150
}


