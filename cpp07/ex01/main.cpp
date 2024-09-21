#include <iostream>
#include "Iter.hpp"

int main(void)
{
    char    arr_c[10] = {"hello"};
    int     arr_i[10] = {1,2,3,4,5};

    std::cout << arr_c << "\n";
    ::iter(arr_c, 5, increment);
    std::cout << arr_c << "\n\n";
    for (int i = 0; i < 5; i++)
        std::cout << arr_i[i] << "\n";
    std::cout << "\n";
    ::iter(arr_i, 5, increment);
     for (int i = 0; i < 5; i++)
        std::cout << arr_i[i] << "\n";
}