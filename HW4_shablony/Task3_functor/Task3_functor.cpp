
#include <iostream>
#include <algorithm>

class get_sum {
    int result = 0;
public:
    void operator ()(const int value) {
        if (value%3 == 0) {
            result +=value;
        }
    }

    int get_result() {
        return result;
    }
};

class get_count {
    int count = 0;
public:
    get_count() : count{ 0 } {};
    void operator()(const int value) {
        if (value % 3 == 0) {
            count++;
        }
    }
    int get_result() {
        return count;
    }
};


int main()
{
    auto M = {4, 1, 3, 6, 25, 54};  //какой-нибудь массив
    get_sum sum;
    get_count cnt;


    
    std::cout << "get_sum() = "<< std::for_each(M.begin(), M.end(), sum).get_result() << '\n';
    std::cout << "get_count() = " << std::for_each(M.begin(), M.end(), cnt).get_result() << '\n';
}

