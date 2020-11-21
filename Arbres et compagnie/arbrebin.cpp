#include "arbrebin.hpp"

ArbreBin::ArbreBin() {
    (*this).racine = new Noeud();
}

ArbreBin::ArbreBin(int _val, int _couleur) {
    (*this).racine = new Noeud(_val, _couleur);
}

static void detruire(Noeud* &n) {
    // EXERCICE
}

ArbreBin::~ArbreBin() {
    detruire(racine);
}

void ArbreBin::afficher(Noeud* n) {
    if(n == NULL) { return;}
    cout << n->get_val() << " ";
    if(!n->get_fg() && !n->get_fd()) { return; }
    cout << "( ";
    afficher(n->get_fg());
    cout << " )";
    if(n->get_fd()) {
        cout << "( ";
        afficher(n->get_fd());
        cout << " )";
    }
}

Noeud* ArbreBin::rechercher(Noeud* n, int _val) {    
    // EXERCICE
}

bool ArbreBin::inserer(int _val) {
    Noeud* tmp = racine;
    Noeud* pere;
    while(tmp != NULL) {
        pere = tmp;
        tmp = tmp->get_fg();
    }
    tmp = new Noeud(_val,-1);
    tmp->set_pere(pere);
    pere->set_fg(tmp);
}

void ArbreBin::supprimer_feuille(Noeud* &n) {
    assert(n != NULL);
    Noeud* pere = n->get_pere();
    if(n == pere->get_fg())
        pere->set_fg(NULL);
    else
        pere->set_fd(NULL);
    delete n;
    n = NULL;
}

void ArbreBin::supprimer_un_fils(Noeud* n) {
    assert(n != NULL);
    Noeud *pere = n->get_pere();
    Noeud* nf;
    if(n->get_fg())
        nf = n->get_fg();
    else
        nf = n->get_fd();
    nf->set_pere(pere);
    if(n == pere->get_fg())
        pere->set_fg(nf);
    else
        pere->set_fd(nf);
    delete n;
}
