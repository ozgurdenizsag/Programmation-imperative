#include "ennemi.hpp"

#include<math.h>

using namespace std;

Ennemi::Ennemi(){
	cout << "Constructeur par défaut." << endl;
	pos_x = 0;
	pos_y = 0;
	vivant = true;
	type = 0;
	score = 0;
}
Ennemi::Ennemi(int _type){
	cout << "Constructeur par avec le type." << endl;
	pos_x = 0;
	pos_y = 0;
	vivant = true;
	type = _type;
	score = 0;
}
Ennemi::Ennemi(int _type, int _pos_x, int _pos_y){
	cout << "Constructeur avec les param." << endl;
	pos_x = _pos_x;
	pos_y = _pos_y;
	vivant = true;
	type = _type;
	score = 0;
}
bool Ennemi::est_vivant(){
	return vivant;
}
void Ennemi::generation(int _type, int L, int H){
	//genere des posions aleatoires des ennemies 
}
void Ennemi::generation( int L, int H){
	//calcule la position suivant des ennemies
}
int Ennemi::get_x(){
	return pos_x;
}
int Ennemi::get_y(){
	return pos_y;
}
char Ennemi::get_symbole(){
	return type;
}
int Ennemi::get_score(){
	return score;
}
void Ennemi::set_mort(){
	vivant = false;
}
bool Ennemi::toucher_par_oiseau(Oiseau& o){
	//verifie si l oiseau touche l ennemi
}
Ennemi::~Ennemi(){

}