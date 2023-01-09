#include <iostream>
#include <map>
#include "../map.hpp"
#include <chrono>  // Pour la mesure du temps d'exécution

int main() {
    // Nombre d'éléments à insérer
    const int n = 1000000;

    // Map de la STL
    std::map<int, int> stl_map;

    // Votre implémentation de la structure de données
    ft::map<int, int> my_map;

    // Mesure du temps d'exécution de l'insertion dans le std::map
    auto start = std::chrono::steady_clock::now(); // Début de la mesure du temps d'exécution 
    for (int i = 0; i < n; ++i) {
        stl_map.insert({i, i});
    }
    auto end = std::chrono::steady_clock::now();    // Fin de la mesure du temps d'exécution
    std::chrono::duration<double> elapsed_seconds = end-start; 
    std::cout << "Temps d'exécution pour std::map : " << elapsed_seconds.count() << " secondes\n";

    // Mesure du temps d'exécution de l'insertion dans votre structure de données
    start = std::chrono::steady_clock::now(); // Début de la mesure du temps d'exécution
    for (int i = 0; i < n; ++i) {
        my_map.insert({i, i});
    }
    end = std::chrono::steady_clock::now(); // Fin de la mesure du temps d'exécution 
    elapsed_seconds = end-start;
    std::cout << "Temps d'exécution pour votre structure de données : " << elapsed_seconds.count() << " secondes\n";

    return 0;
}