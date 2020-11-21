/*! \brief Implémentation de la classe Noeud.
 *
 */
#include "noeud.hpp"

Noeud::Noeud() {
    (*this).fg = NULL;	
    (*this).fd = NULL;
    (*this).pere = NULL;
}

Noeud::Noeud(int _val, int _couleur) {
    (*this).val = _val;
    (*this).couleur = _couleur;
    (*this).fg = NULL;
    (*this).fd = NULL;
    (*this).pere = NULL;
}

Noeud::Noeud(const Noeud &n) {
    (*this).val = n.val;
    (*this).couleur = n.couleur;
    (*this).fg = n.fg;
    (*this).fd = n.fd;
    (*this).pere = n.pere;
}

Noeud::~Noeud() {
}

void Noeud::afficher() {
    cout << (*this).val << " ";
}
