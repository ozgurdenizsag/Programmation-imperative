#include "ennemi.hpp"
#include "oiseau.hpp"
#include "plateau.hpp"
#include <stdio.h>
#include <iostream>

int main(){
	std:: cout << "Hello world!" << std:: endl;
	Oiseau* o = new Oiseau();

	delete o;



	return 0;
}


/*
extern "C" {
	int puts ( char const *);
}*/