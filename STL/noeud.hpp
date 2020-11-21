#ifndef NOEUD_HPP
#define NOEUD_HPP

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

class Noeud {
	private :
		char id;
		int bit;
		Noeud* pred;

	public :
		Noeud();
		Noeud(char _id, int _bit, Noeud* _pred);
		~Noeud();
};


#endif