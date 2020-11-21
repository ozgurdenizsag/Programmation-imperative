#include "oiseau.hpp"

Oiseau::Oiseau(){
	L = 0;
	traj = new int[L];
}

Oiseau::Oiseau(int _L){
	L = _L;
	traj = new int[L];
}

void Oiseau::set_trajectoire(float angle, float vitesse){
	for (int i = 0; i < L; ++i){
		float abs = (float) i;
		float vo_x = vitesse * cos( angle * (M_PI / 180));
		float vo_y = vitesse * sin( angle * (M_PI / 180));
		float y = (-g / (2 * vo_x * vo_x)) * abs * abs + (vo_y / vo_x) * abs;
		traj[i] = round(y);
	}
}

void Oiseau::set_trajectoire(int y_init, int L, int H, float angle){
	// a definir
}

void Oiseau::set_trajectoire(int y_init, int L){
	srand(time(NULL));
	for (int i = 0; i < L; ++i){
		traj[i] = y_init;
	}
}

int Oiseau::get_y(int i){
	return traj[i];
}

void Oiseau::set_grille(int _L){
	L = _L;
	traj = new int[L];
}

Oiseau::~Oiseau(){
	std::cout << "Dest" << std::endl;
	delete[] traj;
}
