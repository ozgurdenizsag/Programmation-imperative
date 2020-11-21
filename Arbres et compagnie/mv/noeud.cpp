#include "noeud.hpp"

Noeud::Noeud(){
	pre = NULL;
	g = NULL;
	d = NULL;
	val = 0;
}

Noeud::Noeud(int _val){
	pre = NULL;
	g = NULL;
	d = NULL;
	val = _val;
}


Noeud::Noeud(Noeud* _pre, Noeud* _g, Noeud* _d, int _val){
	pre = _pre;
	g = _g;
	d = _d;
	val = _val;
}


Noeud::~Noeud(){
	delete g;
	delete d;
}


Noeud* Noeud::getFG(){
	return g;
}	

Noeud* Noeud::getFD(){
	return d;
}

	
void Noeud::setFG(Noeud* newG){
	g = newG;
}	

void Noeud::setFD(Noeud* newD){
	d = newD;
}	

int Noeud::getVal(){
	return val;
}

Noeud* Noeud::getPre(){
	return pre;
}	

void Noeud::setPre(Noeud* newPre){
	pre = newPre;
}


