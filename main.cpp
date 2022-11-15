#include "Vector.hpp"
#include <vector>


int main()
{
    ft::vector<int> value;
   //std::vector<int> val(5, 5);
   //std::vector<int> v(val);
   value.push_back(5);
   value.push_back(4);
   value.push_back(3);
   value.push_back(2);
   value.push_back(1);

   value.pop_back();
   value.resize( 10 , 9);
   //value.push_back(7);
   //value.insert(value.begin() +3, -5);
   std::cout << " size == " << value.size() << std::endl;
   ft::vector<int>::iterator it;
   for (it = value.begin(); it != value.end(); *it++)
   {
     std::cout << *it << std::endl;  
   }  
   
   std::cout <<"cap before reser = " <<  value.capacity() << std::endl;
   value.reserve(13);
   std::cout <<"cap after reser = " <<  value.capacity() << std::endl;
   std::cout << "begin === " << *(value.begin()) << std::endl;
   std::cout <<"end ==== " <<*(value.end()) << std::endl;
   std::cout << "front === " << value.front() << std::endl;
   std::cout << "back === " << value.back() << std::endl;
   std::cout << "size === " << value.max_size() << std::endl;  
}  
  

 
/* 
int main( )
{
   int i;

   ft::vector<int> vec;
   for ( i = 1 ; i < 6 ; ++i )
   {
      vec.push_back ( 2 * i );
   }
   
   ft::vector<int>::iterator vIter;
   std::cout << "The ft:vector vec is: ( ";
   for ( vIter = vec.begin ( ) ; vIter != vec.end ( ); vIter++ )
      std::cout << *vIter << " ";
   std::cout << ")." << std::endl; 
   
   std::vector<int> v;
   for ( i = 1 ; i < 6 ; ++i )
   {
      v.push_back ( 2 * i );
   }
   std::vector<int>::reverse_iterator rIter;
   std::cout << "The vrai:vector vec reversed is: ( ";
   for ( rIter = v.rbegin() ; rIter != v.rend(); rIter++)
      std::cout << *rIter << " ";
   std::cout<< ")." << std::endl; 
   std::cout << "Reverse beg == " << *v.rbegin() << " rend == " << *v.rend() <<std::endl;
   std::cout << "beg == " << *v.begin() << " end == " << *v.end() <<std::endl;
   std::cout << "---------------------------------------------------"<<std::endl;
   ft::vector<int>::reverse_iterator rvIter;

   std::cout << "The ft:vector vec reversed is: ( ";
   for ( rvIter = vec.rbegin() ; rvIter != vec.rend(); rvIter++)
      std::cout << *rvIter << " ";
   std::cout<< ")." << std::endl; 
   std::cout << "---------------------------------------------------"<<std::endl;
   std::cout << "Reverse beg == " << *vec.rbegin() << " rend == " << *vec.rend() <<std::endl;
   std::cout << "beg == " << *vec.begin() << " end == " << *vec.end() <<std::endl;
   std::cout << "---------------------------------------------------"<<std::endl;
}   */