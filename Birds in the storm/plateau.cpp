#include "plateau.hpp"


Plateau::Plateau(int _L,int _H, int _nb_lances, int _nb_e){
	L = _L;
	H = _H;
	nb_lances = _nb_lances;
	nb_ennemis = _nb_e;
}

void Plateau::init_grille(){
	//initalise grille vide
}

void Plateau::init_ennemis(){
	//positionner les ennemis (calculer les positions ennemis)
}

void Plateau::grille_avec_ennemis(){
	//initialise  les ennemis apres avoir initialisé
}

void Plateau::grille_avec_traj(){
	// init traj oiseau
}

void Plateau::traitement_oiseau(){
	//choie oiseau
}

void Plateau::traitement_ennemis(){
	//verifie si ennemie est touché ?
}

void Plateau::jeu(){
	//gestion jeu
}

void Plateau::affichage(){
	//dessine le plato final
}

Plateau::~Plateau(){

}