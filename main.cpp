#include "vector.hpp"
#include "equal.hpp"
#include <vector>
#include "stack.hpp"

int main()
{

   ft::vector<int> vec;

   ft::vector<int>iterator it = vec.begin() + 2;

    for ( int i = 1 ; i < 6 ; ++i ){
      vec.push_back (i);} 
   
   vec.assign(it , vec.end);
   //vec.assign(5, 10);

   /* ft::vector<int> val(5, 5);
   ft::vector<int> v2(vec);
    for ( int i = 1 ; i < 6 ; ++i ){
      vec.push_back (i);} 
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
   vec.insert(vec.begin(), 0 , 55);

     vec.reserve(15);
      std::cout << " last size == " << vec.size() << std::endl;
   std::cout <<"cap after reser = " <<  vec.capacity() << std::endl;
   std::cout << "begin === " << *(vec.begin()) << std::endl;
   std::cout << "front === " << vec.front() << std::endl;
   std::cout << "back === " << vec.back() << std::endl;
   std::cout << "max size === " << vec.max_size() << std::endl;
   std::cout <<"end ==== " <<*(vec.end()) << std::endl;   */
}  


/* int main ()
{
  ft::stack<int> mystack;

   if (mystack.empty() == true)
      std::cout << "stack is empty == true \n";

  for (int i=0; i<5; ++i) mystack.push(i);

   if (mystack.empty() == false)
    std::cout << "stack is not empty == false \n";



  std::cout << "size avant " << mystack.size() << std::endl;
  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
    std::cout << "size apres " << mystack.size() << std::endl;

  return 0;
}
 */
 

/* int main( )
{
   int i;
   ft::vector<int> rvec;
   for ( i = 1 ; i < 6 ; ++i )
   {
      rvec.push_back ( 2 * i );
   }
   
   std::vector<int> v;
   for ( i = 1 ; i < 6 ; ++i )
   {
      v.push_back ( 2 * i );
   }
   std::vector<int>::reverse_iterator rIter;
   std::cout << "The std::vector rvec reversed is: ( ";
   for ( rIter = v.rbegin() ; rIter != v.rend(); rIter++)
      std::cout << *rIter << " ";
   std::cout<< ")." << std::endl; 
   std::cout << "beg == " << *v.begin() << " end == " << *v.end() <<std::endl;
   std::cout << "---------------------------------------------------"<<std::endl;
   ft::vector<int>::reverse_iterator rvIter;
   std::cout << "The ft:vector rvec reversed is: ( ";
   for ( rvIter = rvec.rbegin() ; rvIter != rvec.rend(); rvIter++)
      std::cout << *rvIter << " ";
   std::cout<< ")." << std::endl; 
   std::cout << "---------------------------------------------------"<<std::endl;
   std::cout << "beg == " << *vec.begin() << " end == " << *vec.end() <<std::endl;
   std::cout << "---------------------------------------------------"<<std::endl;
}    */