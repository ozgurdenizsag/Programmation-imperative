/*! \brief Classe Noeud.
 *
 *  Contient tous les éléments associés à un Noeud.
 */
#ifndef NOEUD_HPP
#define NOEUD_HPP

#include <iostream>
using namespace std;

class Noeud {
    private:
        int val; //!< la valeur du Noeud */
        Noeud* fg; //!< pointeur sur le fils gauche du Noeud */
        Noeud* fd; //!< pointeur sur le fils droit du Noeud */
        Noeud* pere; //!< pointeur sur le pere du Noeud */

    public:
        /**
         * Constructeur par défaut. 
         */
        Noeud(); 
        /**
         * Constructeur avec arguments. 
         * @param une valeur entière
         */
        Noeud(int _val); 
        /** 
         * Constructeur par recopie.
         * @param une référence constante sur un Noeud
         */
        Noeud(const Noeud &n); 
        /**
         * Destructeur. 
         */ virtual ~Noeud(); 

        /**
         * Affichage d'un Noeud.
         */
        virtual void afficher(); 

        /**
         * Accesseurs constants
         */
        Noeud* get_fg() const { return fg; }
        Noeud* get_fd() const { return fd; }
        int get_val() const { return val; }

        /**
         * Accesseurs avec référence 
        */
        Noeud* &get_fg() { return fg; }
        Noeud* &get_fd() { return fd; }
        Noeud* &get_pere() { return pere; }

        /**
         * Mutateurs
        */
        void set_val(int _val) { val = _val; }
        void set_fg(Noeud* n) { fg = n; }
        void set_fd(Noeud* n) { fd = n; }
        void set_pere(Noeud* n) { pere = n; }
};
#endif
