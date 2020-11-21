#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<iostream>
#include"oiseau.hpp"
#include"ennemi.hpp"

class Plateau {
	private :
		int L;
		int H;
		int nb_lances;
		int nb_ennemis;
		int nb_vivants;
		Ennemi* E;
		Oiseau o;
		int score;
		char* grille;

	public :
		Plateau(int _L,int _H, int _nb_lances, int _nb_e);
		void init_grille();
		void init_ennemis();
		void grille_avec_ennemis();
		void grille_avec_traj();
		void traitement_oiseau();
		void traitement_ennemis();
		void jeu();
		void affichage();
		~Plateau();
};


#endif