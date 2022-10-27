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
    ft::vector<int>::iterator it = value.begin();
    for (int i =  0; i < 2; i++)
        {
          std::cout << *it << std::endl;  
          it++;
        }
    //std::cout << "begin === " << *(value.begin()) << std::endl;
    //std::cout << *(value.end()) << std::endl;
    //std::cout << "front === " << value.front() << std::endl;
    //std::cout << "back === " << value.back() << std::endl;
    //std::cout << value.capacity() << std::endl;
    std::cout << "size === " << value.size() << std::endl;
}


