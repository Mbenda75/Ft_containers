#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

int main()
{
    std::map<string,unsigned int> nbJoursMois;
    nbJoursMois["zdernier"] = 31;
    nbJoursMois["a1er"] = 28;
    nbJoursMois["b2eme"] = 31;
    nbJoursMois["c3eme"] = 30;
    //...

    std::cout << "La std::map contient " << nbJoursMois.size() << " elements : \n";
    
    for (std::map<string,unsigned int>::iterator it=nbJoursMois.begin(); it!=nbJoursMois.end(); ++
    it)
    {
        std::cout << it->first << " -> \t" << it->second << endl;
    }

     std::cout << "Nombre de jours du mois de janvier : " << nbJoursMois.find("janvier")->second << std::endl;
    // affichage du mois de janvier
    std::map<string,unsigned int>::iterator it=nbJoursMois.begin();
     std::cout << "Janvier : \n" ;

    for (int i=1; i <= it->second; i++)
    {
        std::cout << setw(3) << i;
        if(i%7 == 0)
            std::cout << endl;
    } 
 
    std::cout << endl;
    return 0;
}