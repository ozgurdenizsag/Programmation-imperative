#include "anneau.hpp"

using namespace std;

Anneau::Anneau(){
}

Anneau::Anneau(int taille){
	L.resize(taille);
	char lettre;
	for (std::list<Noeud*>::iterator i = L.begin(); i != L.end(); i++){
		if (i == L.begin()) {
			lettre = 'a';
			*i = new Noeud (lettre, rand()%2 , NULL);
		} else {
			*i = new Noeud (lettre++, rand()%2 , *(i--));
		}
	}
	//(*(L.begin())).set_pred(*(L.end()-1));
}
/*
list<Noeud>::iterator Anneau::prev(list<Noeud>::iterator &it){

}

short Anneau::majorite(){

}

list<Noeud> Anneau::get_anneau(){

}
*/
Anneau::~Anneau(){

}
