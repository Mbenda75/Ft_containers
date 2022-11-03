#include "Vector.hpp"
#include "Vector_iterator.hpp"
#include "Iterator_traits.hpp"
//#include <vector>


 int main()
{
    ft::vector<int> value;
    value.push_back(1);
    value.push_back(2);
    value.push_back(3);
    
    std::cout << "begin === " << *(value.begin()) << std::endl;
    //value.pop_back();
    value.erase(value.begin());
    //value.push_back(7);
    
    ft::vector<int>::iterator it;
    for (it = value.begin(); it != value.end(); *it++)
    {
      std::cout << *it << std::endl;  
    }   

  /*
  std::cout <<"cap before reser = " <<  value.capacity() << std::endl;
  value.reserve(4);
  std::cout <<"cap after reser = " <<  value.capacity() << std::endl;
  std::cout <<"end ==== " <<*(value.end()) << std::endl;
  std::cout << "front === " << value.front() << std::endl;
  std::cout << "back === " << value.back() << std::endl;
  std::cout << "size === " << value.size() << std::endl;
  } */
} 




/* int main ()
{
  std::vector<int> tab {1 , 2 ,6 , 4 ,6};

   std::vector<int>::iterator it;
    tab.erase(tab.begin() + 3);
    for (it = tab.begin(); it != tab.end() ; *it++)
    {
      if (*it == 3)
        std::cout << "it == " << *it << std::endl;
      std::cout << *it << std::endl;  
    } 

}   */