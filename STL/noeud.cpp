#include "noeud.hpp"

using namespace std;

Noeud::Noeud(){
	id = 0;
	bit = 0;
	pred = NULL;
}

Noeud::Noeud(char _id, int _bit, Noeud* _pred){
	id = _id;
	bit = _bit;
	pred = _pred;
}

Noeud::~Noeud(){
	
}
