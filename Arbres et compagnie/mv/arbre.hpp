#ifndef ARBRE_HPP
#define ARBRE_HPP

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<iostream>
#include<time.h>
#include<assert.h>
#include"noeud.hpp"

using namespace std;

class Arbre {
	private :
		Noeud* racine;

	public :
		Arbre();
		Arbre(int val);
		Arbre(Noeud* _racine);
		~Arbre();
		void insert(int val);
		Noeud* recherche(int val);
		void supprimer(int val);
		void afficher();
};


#endif