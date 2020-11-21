#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include "arbre.hpp"

int main(void){

   /* Noeud n(NULL, NULL, 0);
    Noeud* n = new Noeud(NULL,NULL,NULL,0);
    delete n;
    */

    Arbre a(0);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.supprimer(5);
    a.afficher();

	return 0;
}