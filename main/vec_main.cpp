#include "../vector.hpp"


int main()
{
   /*--------------------VECTOR TEST -----------------------------------------------*/
   ft::vector<int>::iterator it;
   ft::vector<int>::const_iterator cit;
   ft::vector<int>::reverse_iterator rit;

   /*--------------------CONSTRUCTEUR TEST ------------------------------*/
   std::cout << "----------------CONSTRUCTEUR TEST--------------------------------" << std::endl;
   ft::vector<int> vec;
   ft::vector<int> vec2(5); // 5 elements 
   ft::vector<int> vec3(5, 100); // 5 elements with value 100
   ft::vector<int> vec4(vec3); // copy of vec3  

   if (vec.empty())
      std::cout << "vec is empty" << std::endl;

   std::cout << "vec2 == ";
   for (it = vec2.begin(); it != vec2.end(); it++)
      std::cout << *it << " ";
   std::cout << std::endl;

   std::cout << "vec3 == ";
   for (it = vec3.begin(); it != vec3.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   std::cout << "vec4 == ";
   for (it = vec4.begin(); it != vec4.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   std::cout << "vec capacity === " << vec.capacity() << "Vec size === " << vec.size() << std::endl;
   vec.push_back(1);
   vec.push_back(2);
   vec.push_back(3);
   vec.push_back(4);
   vec.push_back(5);
   std::cout << "vec capacity === " << vec.capacity() << "Vec size === " << vec.size() << std::endl;

   /*---------------------------CONST ITERATOR TEST--------------------------------------*/
   std::cout << "-----------------CONST ITERATOR TEST-----------------------------" << std::endl;
   std::cout << "vec == ";
   for (cit = vec.begin(); cit != vec.end(); cit++)
      std::cout << *cit << " " ;
   std::cout << std::endl;

   it = vec.begin();
   it[0] = 100;
   std::cout << "it[0] == " << it[0]  << std::endl;
   //cit[2] = 100; //error


   /*-----------------------------------ELEMENT ACCESS-------------------------------------------------*/
   std::cout << "-----------------ELEMENT ACCESS---------------------------------" << std::endl;
   std::cout << "vec[2] == " << vec[2] << std::endl;
   std::cout << "vec.at(2) == " << vec.at(2) << std::endl;


   /*--------------------CAPACITY TEST ------------------------------*/
   std::cout << "------------------------CAPACITY----------------------" << std::endl;
   std::cout << "vec3.size() == " << vec3.size() << std::endl;
   std::cout << "vec.size() == " << vec.size() << std::endl;

   std::cout << "vec3.max_size() == " << vec3.max_size() << std::endl;
   std::cout << "vec3.capacity() == " << vec3.capacity() << std::endl;
   vec.resize(10);
   std::cout << "vec.resize(10) == ";
   for (it = vec.begin(); it != vec.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   vec.resize(5);
   std::cout << "vec.resize(5) == ";
   for (it = vec.begin(); it != vec.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   vec2.assign(5, 9);
   std::cout << "vec2.assign(5, 9) == ";
   for (it = vec2.begin(); it != vec2.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   vec3.assign(vec2.begin(), vec2.end());
   std::cout << "vec3.assign(vec2.begin(), vec2.end()) == ";
   for (it = vec3.begin(); it != vec3.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   vec3.clear();
   std::cout << "vec3.clear() == ";
   for (it = vec3.begin(); it != vec3.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   /*--------------------ASSIGNATION TEST ------------------------------*/
   std::cout << "----------------ASSIGNATION TEST--------------------------------" << std::endl;
   vec3 = vec4;
   std::cout << " new vec == ";
   for (it = vec3.begin(); it != vec3.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   
   /*--------------------Reverse ITERATOR TEST ------------------------------*/
   std::cout << "---------------Reverse ITERATOR TEST --------------------------------" << std::endl;
   std::cout << "vec reverse == ";
   for (rit = vec.rbegin(); rit != vec.rend(); rit++)
      std::cout << *rit << " " ;
   std::cout << std::endl;

   /*---------------------MODIFIERS FUNCITONS TEST -------------------------------*/
   std::cout << "---------------------MODIFIERS FUNCITONS TEST -------------------------------" << std::endl;
   vec.insert(vec.begin(), 10);
   std::cout << "vec.insert(vec.begin(), 10) == ";
   for (it = vec.begin(); it != vec.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   vec.insert(vec.begin(), 2, 20);
   std::cout << "vec.insert(vec.begin(), 2, 20) == ";
   for (it = vec.begin(); it != vec.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   vec.insert(vec.begin(), vec2.begin(), vec2.end());
   std::cout << "vec.insert(vec.begin(), vec2.begin(), vec2.end()) == ";
   for (it = vec.begin(); it != vec.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   vec.erase(vec.begin());
   std::cout << "vec.erase(vec.begin()) == ";
   for (it = vec.begin(); it != vec.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   vec.erase(vec.begin(), vec.end());
   std::cout << "vec.erase(vec.begin(), vec.end()) == ";
   for (it = vec.begin(); it != vec.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   vec.push_back(1);
   vec.push_back(2);
   vec.push_back(3);
   vec.push_back(4);
   vec.push_back(5);

   std::cout << "vec.push_back() == ";
   for (it = vec.begin(); it != vec.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   vec.pop_back();
   std::cout << "vec.pop_back() == ";
   for (it = vec.begin(); it != vec.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   std::cout << "Vec cap avant reserve == " << vec.capacity() << std::endl;
   vec.reserve(20);
   std::cout << "Vec cap apres reserve == " << vec.capacity() << std::endl;

   /*---------------------OPERATOR OVERLOADING TEST -------------------------------*/
   std::cout << "---------------------OPERATOR OVERLOADING TEST -------------------------------" << std::endl;
   std::cout << "vec == ";
   for (it = vec.begin(); it != vec.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   std::cout << "vec2 == ";
   for (it = vec2.begin(); it != vec2.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   std::cout << "vec3 == ";
   for (it = vec3.begin(); it != vec3.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   std::cout << "vec4 == ";
   for (it = vec4.begin(); it != vec4.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

   std::cout << "vec == vec2 == " << (vec == vec2) << std::endl;
   std::cout << "vec == vec3 == " << (vec == vec3) << std::endl;
   std::cout << "vec == vec4 == " << (vec == vec4) << std::endl;
   std::cout << "vec != vec2 == " << (vec != vec2) << std::endl;
   std::cout << "vec != vec3 == " << (vec != vec3) << std::endl;
   std::cout << "vec != vec4 == " << (vec != vec4) << std::endl;

   std::cout << "vec < vec2 == " << (vec < vec2) << std::endl;
   std::cout << "vec < vec3 == " << (vec < vec3) << std::endl;
   std::cout << "vec < vec4 == " << (vec < vec4) << std::endl;
   std::cout << "vec <= vec2 == " << (vec <= vec2) << std::endl;
   std::cout << "vec <= vec3 == " << (vec <= vec3) << std::endl;
   std::cout << "vec <= vec4 == " << (vec <= vec4) << std::endl;
   std::cout << "vec > vec2 == " << (vec > vec2) << std::endl;
   std::cout << "vec > vec3 == " << (vec > vec3) << std::endl;
   std::cout << "vec > vec4 == " << (vec > vec4) << std::endl;
   std::cout << "vec >= vec2 == " << (vec >= vec2) << std::endl;
   std::cout << "vec >= vec3 == " << (vec >= vec3) << std::endl;

   vec.swap(vec2);
   std::cout << "vec.swap(vec2) == ";
   for (it = vec.begin(); it != vec.end(); it++)
      std::cout << *it << " " ;
   std::cout << std::endl;

}