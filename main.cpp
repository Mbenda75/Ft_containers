#include "Vector.hpp"
#include "Vector_iterator.hpp"
#include "Iterator_traits.hpp"
#include <vector>


 int main()
{
   ft::vector<int> value;
   //std::vector<int> val(5, 5);
   //std::vector<int> v(val);
    value.push_back(1);
    value.push_back(2);
    value.push_back(3);
    value.push_back(4);
    value.push_back(5);

    //value.pop_back();
    //value.resize( 7 , 9);
    //value.push_back(7);
   value.insert(value.begin()+ 2, 2, 0);
   std::cout << " size == " << value.size() << std::endl;
    ft::vector<int>::iterator it;
    for (it = value.begin(); it != value.end(); *it++)
    {
      std::cout << *it << std::endl;  
    }   
}
  
 /*  
   std::cout <<"cap before reser = " <<  value.capacity() << std::endl;
  value.reserve(6);
  std::cout <<"cap after reser = " <<  value.capacity() << std::endl;
  std::cout << "begin === " << *(value.begin()) << std::endl;
  std::cout <<"end ==== " <<*(value.end()) << std::endl;
  std::cout << "front === " << value.front() << std::endl;
  std::cout << "back === " << value.back() << std::endl;
  std::cout << "size === " << value.size() << std::endl; */


/*
int main( )
{
   int i;

   ft::vector<int> vec;
   for ( i = 1 ; i < 6 ; ++i )
   {
      vec.push_back ( 2 * i );
   
   ft::vector<int>::iterator vIter;
   std::cout << "The ft:vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++ )
      std::cout << *vIter << " ";
   std::cout << ")." << std::endl;

    ft::vector<int>::reverse_iterator rvIter;
   std::cout << "The ft:vector vec reversed is: ( ";
   for ( rvIter = vec.rbegin( ) ; rvIter != vec.rend( ); rvIter++)
      std::cout << *rvIter << " ";
   std::cout<< ")." << std::endl; 
}
 */
 


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