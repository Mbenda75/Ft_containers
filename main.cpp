#include "Vector.hpp"
#include "Vector_iterator.hpp"
#include "Iterator_traits.hpp"
#include <vector>
int main()
{
    ft::vector<int> value;
    value.push_back(5);
    value.push_back(6);
    value.push_back(7);
    //ft::vector<int>::iterator  it = value.begin(); 
    ft::vector<int>::iterator it;
    for (it = value.begin(); it != value.end(); it++)
        std::cout << *it << std::endl;  
    //std::cout << *(value.begin()) << std::endl;
    //std::cout << *(value.end()) << std::endl;
    //std::cout << value.capacity() << std::endl;
    //std::cout << value.size() << std::endl;
}


