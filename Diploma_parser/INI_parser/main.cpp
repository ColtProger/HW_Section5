#include <iostream>
#include "IniParser.h"




int main() {

    setlocale(LC_ALL, "Russian"); // задаём русский текст
    system("chcp 1251"); // настраиваем кодировку консоли
    
    try {
       
        IniParser parser("text.ini");

        //проверка int
         //auto value = parser.getValue<int>("var1", "Section2");
        //std::cout << value << std::endl;
       
       
        // проверка float
        //auto value1 = parser.getValue<double>("var1", "Section1");
        //std::cout << value1 << std::endl;

        // проверка на поиск некорректной строки
       // auto value2 = parser.getValue<int>("Mode", "Section4");
       // std::cout << value2 << std::endl;

        // проверка на поиск строки
        auto value3 = parser.getValue<std::string>("var2", "Section1");
        std::cout << value3 << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;

}