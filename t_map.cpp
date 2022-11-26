#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

int main()
{
    std::map<string,unsigned int> nbJoursMois;
    nbJoursMois["janvier"] = 31;
    nbJoursMois["février"] = 28;
    nbJoursMois["mars"] = 31;
    nbJoursMois["avril"] = 30;
    //...

    std::cout << "La std::map contient " << nbJoursMois.size() << " elements : \n";
    
    for (std::map<string,unsigned int>::iterator it=nbJoursMois.begin(); it!=nbJoursMois.end(); ++
    it)
    {
        std::cout << it->first << " -> \t" << it->second << endl;
    }

     std::cout << "Nombre de jours du mois de janvier : " << nbJoursMois.find("janvier")->second << std::endl;
    // affichage du mois de janvier

    std::cout << "Janvier : \n" ;

    for (int i=1; i <= nbJoursMois["février"]; i++)
    {
        std::cout << setw(3) << i;
        if(i%7 == 0)
            std::cout << endl;
    }
 
    std::cout << endl;
    return 0;
}