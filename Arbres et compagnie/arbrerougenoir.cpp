#include "arbrerougenoir.hpp"

Arbrerougenoir::Arbrerougenoir() : ArbreBinRec() {}
Arbrerougenoir::Arbrerougenoir(int _val, int _couleur) : ArbreBinRec(_val, _couleur) {}
Arbrerougenoir::~Arbrerougenoir() {
}

Noeud* Arbrerougenoir::parent(Noeud* n){
    return n->get_pere();
}

Noeud* Arbrerougenoir::grandparent(Noeud* n){
    return parent(parent(n));
}

Noeud* Arbrerougenoir::oncle(Noeud* n){
    return frere(parent(n));
}

Noeud* Arbrerougenoir::frere(Noeud* n){
    Noeud* papa = parent(n);
    if ( (papa->get_fg())->get_val() == n->get_val() ){
        return papa->get_fd();
    } else {
        papa->get_fg();
    }
}

void Arbrerougenoir::rotationGauche(Noeud* n){

}

void Arbrerougenoir::rotationDroite(Noeud* n){
    Noeud* p = parent(n);
    Noeud* fg = n->get_fg();
    n->set_fg(fg->get_fd());
    n->set_pere(fg);
    fg->set_pere(NULL);
    fg->set_fd(n);
    if( p == NULL ){
        racine = fg;
    }
}

