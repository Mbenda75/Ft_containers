#include "Vector.hpp"
#include "Vector_iterator.hpp"
#include "Iterator_traits.hpp"
#include <vector>
int main()
{
   ft::vector<int> value;
    value.push_back(5);
    ft::vector<int>::iterator  it = value.begin(); 
    std::cout << *(value.begin()) << std::endl;
    value.push_back(6);
     //ft::vector<int>::iterator it;
   // for (it = value.begin(); it != value.end(); it++)
     //   std::cout << *it << std::endl;  
}


