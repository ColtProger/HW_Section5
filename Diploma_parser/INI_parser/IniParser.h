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

    IniParser(const std::string& filename); // �����������

    void parseFromFile(const std::string& filename);  // ��������������� ������

    std::string getString(const std::string& key, const std::string& section) const;  // ����� ��������� ��������-������
    
    template<typename T>
    T getValue(const std::string& key, const std::string& section) const; 
    //�������������

    template<>
    int getValue<int>(const std::string& key, const std::string& section) const; 

    template<>
    double getValue<double>(const std::string& key, const std::string& section) const;

    template<>
    std::string getValue<std::string>(const std::string& key, const std::string& section) const;  

private:
    std::unordered_map<std::string, std::map<std::string, std::string>> ini_data; // ������ INI-�����

    template<typename T>
    T convert(const std::string& str, bool& aOk = nullptr) const; // ��������� ����� ��� ����������� ��������

    //�������������
    template<>
    int convert<int>(const std::string& str, bool& aOk) const; 

    template<>
    double convert<double>(const std::string& str, bool& aOk) const; 

    template<>
    std::string convert<std::string>(const std::string& str, bool& aOk) const; 
};
