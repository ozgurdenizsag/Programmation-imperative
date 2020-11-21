#ifndef NOEUDCOLORE_HPP
#define NOEUDCOLORE_HPP

#include <iostream>
using namespace std;

class Noeudcolore : public noeud{
    private:
     int couleur;
    public:
        /**
         * Constructeur par défaut. 
         */
        Noeudcolore(); 
        /**
         * Constructeur avec arguments. 
         * @param une valeur entière
         */
        Noeudcolore(int _val, int coul); 
        /** 
         * Constructeur par recopie.
         * @param une référence constante sur un Noeud
         */
        Noeudcolore(const Noeud &n, int coul); 
        /**
         * Destructeur. 
         */ virtual ~Noeud(); 
        /**
         * Affichage d'un Noeud.
         */
        virtual void afficher(); 

        /**
         * Accesseurs
         */
        int get_couleur() const { return couleur; }
        /**
         * Mutateurs
        */
        void set_couleur(int coul) { couleur = coul; }    
};
#endif
