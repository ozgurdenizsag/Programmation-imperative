#ifndef ARBREBIN_HPP
#define ARBREBIN_HPP
#include "noeud.hpp"
#include <assert.h>

class ArbreBin {
    // Pour accès depuis classe Fille
    protected:
        Noeud* racine;
    public:
        ArbreBin();
        ArbreBin(int _val, int _couleur);
        // Héritage : destructeur virtuel
        virtual ~ArbreBin();

        Noeud* get_racine() const { return racine; }

        // Méthodes propres à Arbre binaire
        void afficher(Noeud* n); // Vraiment ?
        void supprimer_feuille(Noeud* &n);
        void supprimer_un_fils(Noeud* n);

        // Méthodes virtuelles --- redéfinition possible 
        virtual Noeud* rechercher(Noeud *n, int _val);
        virtual bool inserer(int _val);

        // Méthodes virtuelles pures --- redéfinition obligatoire
        virtual bool inserer(Noeud* &ins, Noeud* pere, int _val) = 0;
        virtual bool supprimer(int _val) = 0;
};
#endif
