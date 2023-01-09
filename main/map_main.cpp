#include "../map.hpp"
#include <map>


int main ()
{
    //create empty map container
    ft::map<char,int> mymap;
    ft::map<char , int> mymap2;

    mymap2['g'] = 800;
    mymap2['h'] = 900;
    mymap2['i'] = 1000;
    
    //insert elements in random order
    mymap.insert (ft::pair<char,int>('a',100) );
    mymap.insert (ft::pair<char,int>('z',200) );
    mymap.insert (ft::pair<char,int>('b',300) );

    //print content:
    std::cout << "mymap contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    /*ELEMENT ACCESS */
    std::cout << "------------------ELEMENT ACCES----------------------------\n";
    std::cout << "mymap['a'] == " << mymap['a'] << std::endl;
    std::cout << "mymap['b'] == " << mymap['b'] << std::endl;
    std::cout << "mymap['z'] == " << mymap['z'] << std::endl;

    /*ITERATOR*/
    std::cout << "--------------- ITERATOR ----------------------------\n";
    ft::map<char,int>::iterator it = mymap.begin();
    ft::map<char,int>::iterator it3 = mymap.find('a');
    ft::map<char,int>::iterator it4 = mymap.find('z');
    ft::map<char,int>::iterator it5 = mymap.find('z');

    std::cout << "it == " << it->first << std::endl;
    std::cout << "it3 == " << it3->first << std::endl;
    std::cout << "it4 == " << it4->first << std::endl;
    std::cout << "it5 == " << it5->first << std::endl;

    /*CONST ITERATOR*/
    std::cout << "------------------CONST ITERATOR ----------------------------\n";
    ft::map<char,int>::const_iterator cit = mymap.begin();
    ft::map<char,int>::const_iterator cit3 = mymap.find('a');

    std::cout << "cit == " << cit->first << std::endl;
    std::cout << "cit3 == " << cit3->first << std::endl;

    /*REVERSE ITERATOR*/
    std::cout << "------------------REVERSE ITERATOR ----------------------------\n";
    ft::map<char,int>::reverse_iterator rit = mymap.rbegin();
    ft::map<char,int>::reverse_iterator rit3 = mymap.rbegin();

    std::cout << "rit == " << rit->first << std::endl;
    std::cout << "rit3 == " << rit3->first << std::endl;

    /*CONST REVERSE ITERATOR*/
    std::cout << "------------------CONST REVERSE ITERATOR ----------------------------\n";
    ft::map<char,int>::const_reverse_iterator crit = mymap.rbegin();
    ft::map<char,int>::const_reverse_iterator crit3 = mymap.rbegin();

    std::cout << "crit == " << crit->first << std::endl;
    std::cout << "crit3 == " << crit3->first << std::endl;

    /*CAPACITY*/
    std::cout << "------------------CAPACITY ----------------------------\n";
    if(mymap.empty() == 0)
        std::cout << "mymap is not empty" << std::endl;
    else
        std::cout << "mymap is empty" << std::endl;
    std::cout << "mymap.size() == " << mymap.size() << std::endl;
    std::cout << "mymap.max_size() == " << mymap.max_size() << std::endl;

    /*MODIFIERS*/
    std::cout << "------------------MODIFIERS ----------------------------\n";
    mymap.insert (ft::pair<char,int>('c',400) );
    mymap.insert (ft::pair<char,int>('d',500) );
    mymap.insert (ft::pair<char,int>('e',600) );
    mymap.insert (ft::pair<char,int>('f',700) );


    std::cout << "mymap contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    mymap.insert(mymap2.begin(), mymap2.end());

    std::cout << "mymap contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    mymap.erase (mymap.begin());
    mymap.erase ('c');


    std::cout << "mymap contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    mymap.erase (mymap.begin(), mymap.find('e'));
    std::cout << "mymap contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    mymap.swap(mymap2);
    std::cout << "mymap contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    std::cout << "mymap2 contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap2.begin(); it!=mymap2.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    
    //mymap.clear();
    //mymap2.clear();

    
    std::cout << "mymap contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    
    std::cout << "mymap2 contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap2.begin(); it!=mymap2.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    

    /*OPERATIONS*/
    std::cout << "------------------OPERATIONS ----------------------------\n";
    ft::map<char,int> mymap3;
    ft::map<char,int> mymap4;

    mymap3['a']=10;
    mymap3['b']=20;
    mymap3['c']=30;

    mymap4['x']=100;
    mymap4['y']=200;
    mymap4['z']=300;

    std::cout << "mymap3 contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap3.begin(); it!=mymap3.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    
    std::cout << "mymap4 contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap4.begin(); it!=mymap4.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    std::cout << "mymap3 == mymap4 ? " << (mymap3 == mymap4) << std::endl;
    std::cout << "mymap3 != mymap4 ? " << (mymap3 != mymap4) << std::endl;
    std::cout << "mymap3 < mymap4 ? " << (mymap3 < mymap4) << std::endl;
    std::cout << "mymap3 > mymap4 ? " << (mymap3 > mymap4) << std::endl;
    std::cout << "mymap3 <= mymap4 ? " << (mymap3 <= mymap4) << std::endl;
    std::cout << "mymap3 >= mymap4 ? " << (mymap3 >= mymap4) << std::endl;

    /*LOOKUP COUNT*/
    std::cout << "------------------LOOKUP COUNT ----------------------------\n";
    ft::map<char,int> mymap5;
    ft::map<char,int>::iterator itlow,itup;

    mymap5['a']=20;
    mymap5['b']=40;
    mymap5['c']=60;
    mymap5['d']=80;
    mymap5['e']=100;

    itlow=mymap5.lower_bound ('b');  // itlow points to b
    itup=mymap5.upper_bound ('d');   // itup points to e (not d!)


    std::cout << "itlow->first = " << itlow->first << std::endl;
    std::cout << "itlow->second = " << itlow->second << std::endl;

    std::cout << "itup->first = " << itup->first << std::endl;
    std::cout << "itup->second = " << itup->second << std::endl;
    
    mymap5.erase(itlow,itup);        // erases [itlow,itup)

    // print content:
    std::cout << "mymap5 contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap5.begin(); it!=mymap5.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    /*OBSERVERS*/
    std::cout << "------------------OBSERVERS ----------------------------\n";


    ft::map<char,int> mymap6;
    ft::map<char,int>::key_compare mycomp = mymap6.key_comp();
    ft::map<char,int>::value_compare mycomp2 = mymap6.value_comp();

    mymap6['a']=100;
    mymap6['b']=200;
    mymap6['c']=300;

    std::cout << "mymap6 contains:"<< std::endl;
    char highest = mymap6.rbegin()->first;     // key value of last element

    ft::map<char,int>::iterator ite = mymap6.begin();
    do {
        std::cout << ite->first << " => " << ite->second << std::endl;
    } while ( mycomp((*ite++).first, highest) );

    std::cout << "mymap6 contains:"<< std::endl;
    ft::pair<char,int> highest2 = *mymap6.begin();          // last element

    ft::map<char,int>::iterator ite2 = mymap6.begin();
    do {
        std::cout << ite2->first << " => " << ite2->second << std::endl;
    } while ( mycomp2(*ite2++, highest2) );

    /*EQUAL RANGE*/
    std::cout << "------------------EQUAL RANGE ----------------------------\n";
    ft::map<char,int> mymap7;

    mymap7['a']=10;
    mymap7['b']=20;
    mymap7['c']=30;

    std::cout << "mymap7 contains:"<< std::endl;
    for (ft::map<char,int>::iterator it=mymap7.begin(); it!=mymap7.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    
    ft::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ret;
    ret = mymap7.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << std::endl;

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << std::endl;




}
