#ifndef NOEUD_HPP
#define NOEUD_HPP

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<iostream>

class Noeud {
	private :
		Noeud* pre;
		Noeud* g;
		Noeud* d;
		int val;

	public :
		Noeud();
		Noeud(int _val);
		Noeud(Noeud* _pre, Noeud* _g, Noeud* _d, int _val);
		~Noeud();
		Noeud* getFG();		
		Noeud* getFD();	
		Noeud* getPre();	
		int getVal();

		void setPre(Noeud* newPre);
		void setFG(Noeud* newG);		
		void setFD(Noeud* newD);

};


#endif