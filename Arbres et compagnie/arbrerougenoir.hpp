#ifndef ARBREROUGENOIR_HPP
#define ARBREROUGENOIR_HPP

#include <iostream>
#include "arbrebinrec.hpp"
using namespace std;

class Arbrerougenoir : public ArbreBinRec {
    public:
        Arbrerougenoir();
        Arbrerougenoir(int _val, int _couleur);
        ~Arbrerougenoir();

        Noeud* parent(Noeud* n);
        Noeud* grandparent(Noeud* n);
        Noeud* oncle(Noeud* n);
        Noeud* frere(Noeud* n);

        void rotationGauche(Noeud* n);
        void rotationDroite(Noeud* n);

};
#endif
