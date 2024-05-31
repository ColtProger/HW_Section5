#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>

class BigNumber {
private:
    size_t size = 0;
    bool isNegative = false;
    std::vector<int> digits;

public:
    BigNumber(std::string aValue);
    ~BigNumber();

    BigNumber(BigNumber&& other) noexcept;

    BigNumber(BigNumber& other) noexcept;
    
    BigNumber& operator=(BigNumber&& other) noexcept; // оператор перемещающего присваивания    
 
    BigNumber& operator=(BigNumber& other) noexcept; // оператор перемещающего присваивания    
    
    BigNumber operator+(const BigNumber& other); 

    BigNumber operator*(int num);

    friend  std::ostream& operator<<(std::ostream& os, const BigNumber& num);
};

std::ostream& operator<<(std::ostream& os, const BigNumber& num); 
