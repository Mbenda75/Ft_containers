#include "vector.hpp"
#include "equal.hpp"
#include <vector>

int main()
{
   ft::vector<int> vec;
   //ft::vector<int> val(5, 5);
    //ft::vector<int> v2(vec);
    for ( int i = 1 ; i < 6 ; ++i ){
      vec.push_back (i);} 
      //vec.assign(5, 10);
    std::cout << " size avant resize== " << vec.size() << std::endl;
   vec.pop_back();
   std::cout << " size avant resize== " << vec.size() << std::endl;
   vec.resize( 10 , 9);
    std::cout << " size avant resize== " << vec.size() << std::endl;
   vec.push_back(7);
   std::cout <<"cap before reser = " <<  vec.capacity() << std::endl;
   ft::vector<int>::iterator it;
   for (it = vec.begin(); it != vec.end(); *it++)
   {
     std::cout << *it << std::endl;  
   }  
   std::cout << "INSERT NOW \n";

     vec.reserve(15);
      std::cout << " last size == " << vec.size() << std::endl;
   std::cout <<"cap after reser = " <<  vec.capacity() << std::endl;
   std::cout << "begin === " << *(vec.begin()) << std::endl;
   std::cout << "front === " << vec.front() << std::endl;
   std::cout << "back === " << vec.back() << std::endl;
   std::cout << "max size === " << vec.max_size() << std::endl;
   std::cout <<"end ==== " <<*(vec.end()) << std::endl;  
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