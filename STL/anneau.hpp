#ifndef ANNEAU_HPP
#define ANNEAU_HPP

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<iostream>
#include<list>
#include"noeud.hpp"

using namespace std;

class Anneau {
	private :
		list<Noeud*> L;
	public :
		Anneau();
		Anneau(int taille);
		~Anneau();

		list<Noeud>::iterator prev(list<Noeud>::iterator &it);

		short majorite();

		list<Noeud> get_anneau();
};


#endif