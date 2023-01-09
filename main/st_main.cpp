#include "../stack.hpp"

 int main ()
{
    /*-----------------------STACK TEST ---------------------------------*/
    std::cout << "-----------------------STACK TEST ---------------------------------" << std::endl;
 
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

    /*--------------------OPERATOR --------------------*/
    std::cout << "-----------------------OPERATOR TEST ---------------------------------" << std::endl;
    ft::stack<int> mystack2;
    ft::stack<int> mystack3;

    mystack2.push(10);
    mystack2.push(20);
    mystack2.push(30);
    mystack2.push(40);

    mystack3.push(10);
    mystack3.push(20);
    mystack3.push(30);
    mystack3.push(40);

    if (mystack2 == mystack3)
        std::cout << "mystack2 == mystack3" << std::endl;
    else
          std::cout << "mystack2 != mystack3" << std::endl;

    mystack3.push(50);
    if (mystack2 != mystack3)
        std::cout << "mystack2 != mystack3" << std::endl;
    else
          std::cout << "mystack2 == mystack3" << std::endl;
    
    
    /*--------------------RELATIONAL OPERATOR --------------------*/
    std::cout << "-----------------------RELATIONAL OPERATOR TEST ---------------------------------" << std::endl;
    ft::stack<int> mystack4;

    mystack4.push(1);
    mystack4.push(2);
    mystack4.push(3);
    mystack4.push(4);

    if (mystack2 < mystack4)
        std::cout << "mystack2 < mystack4" << std::endl;
    else
          std::cout << "mystack2 > mystack4" << std::endl;

    mystack3.pop();
    if (mystack2 >= mystack3)
        std::cout << "mystack2 >= mystack3" << std::endl;
    else
        std::cout << "mystack2 <= mystack3" << std::endl;

 return 0;
}
 