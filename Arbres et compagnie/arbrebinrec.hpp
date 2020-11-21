#ifndef ARBREBINREC_HPP
#define ARBREBINREC_HPP

#include "arbrebin.hpp"

class ArbreBinRec : public ArbreBin {
    public:
        ArbreBinRec();
        ArbreBinRec(int _val, int _couleur);
        ~ArbreBinRec();

        // Méthodes virtuelles (pures ou non) redéfinies
        Noeud* rechercher(Noeud* n, int _val);
        bool inserer(int _val);
        bool inserer(Noeud* &ins, Noeud *n, int _val);
        bool supprimer(int _val); 
};
#endif
