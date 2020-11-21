#ifndef OISEAU_HPP
#define OISEAU_HPP

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<iostream>
#include<time.h>
#define g 9.8

using namespace std;

class Oiseau {
	private :
		int L;
		int* traj;

	public :
		Oiseau();
		Oiseau(int _L);
		void set_trajectoire(float angle, float vitesse);
		void set_trajectoire(int y_init, int L, int H, float angle);
		void set_trajectoire(int y_init, int L);
		int get_y(int i);
		void set_grille(int _L);
		~Oiseau();
};


#endif