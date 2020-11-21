#include "arbrebinrec.hpp"

ArbreBinRec::ArbreBinRec() : ArbreBin() {}

ArbreBinRec::ArbreBinRec(int _val) : ArbreBin(_val) {}

ArbreBinRec::~ArbreBinRec() {
}

Noeud* ArbreBinRec::rechercher(Noeud* n, int _val) {
    if(n == NULL) return NULL;
    else if(n->get_val() == _val)
        return n;
    else if(n->get_val() > _val)
        return rechercher(n->get_fg(), _val);
    else
        return rechercher(n->get_fd(), _val);
}

// Insertion classique
bool ArbreBinRec::inserer(int _val) {
    Noeud *tmp = racine;
    Noeud *pere_tmp;

    while(tmp != NULL) {
        pere_tmp = tmp;
        if(tmp->get_val() == _val)
            return false;
        else if (tmp->get_val() > _val)
            tmp = tmp->get_fg();
        else
            tmp = tmp->get_fd();
    }
    tmp = new Noeud(_val);
    tmp->set_pere(pere_tmp);
    if(pere_tmp->get_val() > _val)
        pere_tmp->set_fg(tmp);
    else
        pere_tmp->set_fd(tmp);
    return true;
}

// Insertion récursive --- surcharge de fonctions
bool ArbreBinRec::inserer(Noeud* &ins, Noeud* pere, int _val) {
    if(rechercher(racine, _val)) return false;
    if(ins == NULL) {
        ins = new Noeud(_val);
        ins->set_pere(pere);
        return true;
    }
    else if(ins->get_val() > _val)  
        inserer(ins->get_fg(), ins, _val);
    else
        inserer(ins->get_fd(), ins, _val);
    return false;
}

// Méthode statique --- utilisable depuis ce fichier *uniquement*
static void supprimer_noeud(ArbreBinRec &a, Noeud *n) {
    if(n == NULL) { return; }
    // Fils droit le plus à gauche
    Noeud *tmp = n->get_fd();
    while(tmp->get_fg() != NULL)
        tmp = tmp->get_fg();
    // Permutation
    int c = n->get_val();
    n->set_val(tmp->get_val());
    tmp->set_val(c);
    // Suppression
    if(tmp->get_fd())
        a.supprimer_un_fils(tmp);
    else 
        a.supprimer_feuille(tmp);
}

bool ArbreBinRec::supprimer(int _val) {
    Noeud *n = rechercher(racine, _val);
    // Différentes actions selon le(s) cas
    if(!n) { return false; }
    else if(!n->get_fg() && !n->get_fd()) 
        supprimer_feuille(n); 
    else if(!n->get_fg() || !n->get_fd())
        supprimer_un_fils(n);
    else 
        supprimer_noeud(*this, n);
    return true;
}

