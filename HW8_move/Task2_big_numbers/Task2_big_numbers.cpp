#include <iostream>
#include<string>
#include<cstring>
#include<vector>
#include"BigNumber.h"


int main()
{
	try {
		auto number1 = BigNumber("114575");
		auto number2 = BigNumber("78524");
		auto result = number1 + number2;
		std::cout << "sum: " << result << std::endl; // 193099

		auto result2 = number1 * 2;
		std::cout << "multipl: " << result2 << std::endl; // 229150
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}


