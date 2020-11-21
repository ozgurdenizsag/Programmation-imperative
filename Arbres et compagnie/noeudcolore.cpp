#include "noeudcolore.hpp"

Noeudcolore::Noeudcolore() : Noeud() , couleur(1) {}

Noeudcolore::Noeudcolore(int _val, int coul) : Noeud(_val) , couleur(coul) {}

Noeudcolore::Noeudcolore(const Noeud &n, int coul) : Noeud(&n) , couleur(coul) {}

Noeudcolore::~Noeudcolore() {}

void Noeudcolore::afficher() {
    cout << get_val() << (*this).couleur << " ";
}