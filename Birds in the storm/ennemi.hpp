#ifndef ENNEMI_HPP
#define ENNEMI_HPP

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include <iostream>
#include "oiseau.hpp"

class Ennemi {
	private :
		int pos_x;
		int pos_y;
		bool vivant;
		int type;
		int score;

	public :
		Ennemi();
		Ennemi(int _type);
		Ennemi(int _type, int _pos_x, int _pos_y);
		bool est_vivant();
		void generation(int _type, int L, int H);
		void generation( int L, int H);
		int get_x();
		int get_y();
		char get_symbole();
		int get_score();		
		void set_mort();
		bool toucher_par_oiseau(Oiseau& o);
		~Ennemi();
};


#endif