#include <iostream>
#include <string>
#include <map>
#include <iomanip>


int main()
{
    std::map<char, int> mp;
    std::string str;

    std::cout << "Enter your string: " << std::endl;
    std::getline(std::cin, str);

    for (auto i : str)   ++mp[i];
   

    std::multimap<int, char, std::greater<int>> mp2;
     for (auto i : mp) {
       mp2.insert({ i.second, i.first });
    }
     for (auto i : mp2) {
         std::cout << "\n" << i.second << " : " << i.first;
     }
    return 0;
}

