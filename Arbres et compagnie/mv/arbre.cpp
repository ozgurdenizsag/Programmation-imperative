#include "arbre.hpp"

using namespace std;

	Arbre::Arbre(){
		racine = NULL;
	}

	Arbre::Arbre(Noeud* _racine){
		racine = _racine;
	}

	Arbre::Arbre(int val){
		racine = new Noeud(val);
	}

	Arbre::~Arbre(){
		delete racine;
	}

	void Arbre::insert(int val){
		if ( racine != NULL ){
			assert (recherche(val) == NULL);
   			Noeud* n = racine;	
			while (n->getFG() != NULL) {
				n = n->getFG();
			}
			n->setFG(new Noeud(val)); //erreur
			(n->getFG())->setPre(n);
		} else {
			racine = new Noeud(val);
		}
	}

	Noeud* Arbre::recherche(int val){
		if ( racine != NULL ){
   			Noeud* n = racine;	
			while (n != NULL) {
				if (val == n->getVal()){
					return n;
				}
				n = n->getFG();
			}
		}
		return NULL;
	}

	void Arbre::supprimer(int val){
		if ( racine != NULL ){
			Noeud* n= recherche(val);
			if (n != NULL){
				if(n.getFG() != NULL){
					// A coder.
				}
			} else {
				std::cout << "Valeur inexistant." << std::endl;
			}
		} else {
			std::cout << "Rien à supprimer." << std::endl;
		}
	}

	void Arbre::afficher(){
		if ( racine != NULL ){
   			Noeud* n = racine;	
			while (n != NULL) {
				std::cout << n->getVal() << std::endl;
				n = n->getFG();
			}
		} else {
			std::cout << "Arbre Vide." << std::endl;
		}
	}
