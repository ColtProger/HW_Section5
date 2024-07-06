#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<map>
#include<vector>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <unordered_map>

class IniParser {
public:

    IniParser(const std::string& filename); // Конструктор

    void parseFromFile(const std::string& filename);  // непосредственно парсер

    std::string getString(const std::string& key, const std::string& section) const;  // Метод получения значения-строки
    
    template<typename T>
    T getValue(const std::string& key, const std::string& section) const {
        staticassert(sizeof(T) == -1, "not implemented type for get_value");
    };
    
    
    
    //специализация

    template<>
    int getValue<int>(const std::string& key, const std::string& section) const
    {
        std::string value = getString(key, section);

        if (value.empty()) {
            throw std::runtime_error("Invalid line format: " + key + "=");
        }
        else {

            try { 
                const auto str{ std::stoi(value.c_str()) };
                return str;
                }
            catch (...) {
                throw std::runtime_error("Type of variable is incorrect");
            }
           
        }

       // return {};
    }

    template<>
    double getValue<double>(const std::string& key, const std::string& section) const
    {
        std::string value = getString(key, section);

        if (value.empty()) {
            throw std::runtime_error("Invalid line format: " + key + "=");
        }
        else {

            try {
                const auto str{ std::stof(value.c_str()) };
                return str;
            }
            catch (...) {
                throw std::runtime_error("Type of variable is incorrect");
            }

        }
    };

    template<>
    std::string getValue<std::string>(const std::string& key, const std::string& section) const
    {
        std::string value = getString(key, section);

        if (value.empty()) {
            throw std::runtime_error("Invalid line format: " + key + "=");
        }
        else {
           return value;
        }
        //return;
    };

private:
    std::unordered_map<std::string, std::map<std::string, std::string>> ini_data; // Данные INI-файла

};
