#include "arbrebinrec.hpp"

int main() {
    ArbreBinRec *A = new ArbreBinRec(1);
    Noeud* racine_A = A->get_racine();

    A->inserer(racine_A, NULL, 3); 
    A->inserer(racine_A, NULL, 8);
    // ne respecte pas l'arbre binaire mais fonctionne
    // A->ArbreBin::inserer(6);
    A->inserer(6);
    A->inserer(racine_A, NULL, 4);
    A->inserer(racine_A, NULL, 7);
    A->inserer(racine_A, NULL, 10);
    A->inserer(racine_A, NULL, 14);
    A->inserer(racine_A, NULL, 13);

    A->afficher(racine_A);
    cout << endl;
    A->supprimer(7); 
    A->supprimer(14);
    A->afficher(racine_A);
    cout << endl;
    A-> supprimer(8);
    A->afficher(racine_A);
    cout << endl;
	delete A;
    return 0;
}
