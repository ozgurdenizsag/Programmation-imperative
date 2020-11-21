#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include"anneau.hpp"


void detect1(const std::vector<int> &v){
	int nb = -1;
	int rep = 0;
	int exist = 0;
	for(int i = 0; i < v.size(); i++){
		nb = v[i];
		rep = 0;
    	for(int j = i; j < v.size(); j++){
    		if (nb == v[j]){
    			rep++;
    		}
    	}
    	if (rep >= (v.size() / 2)){
    		exist = 1;
    		break;
    	}
    }
    if (exist == 1){
    	printf("Majorant est %d avec %d repetition.\n", nb, rep);
    } else {
    	printf("Pas de majorant\n");
    }
}

void detect2(std::vector<int> &v){
	int nb = -1;
	int rep = 0;
	int exist = 0;
	std::sort(v.begin(),v.end());

	nb = v[0];
	rep = 0;

	for(int i = 0; i < v.size(); i++){
		
		if(nb ==  v[i]){
			rep++;
		} else {
			nb = v[i];
			rep = 1;
		}

    	if (rep >= (v.size() / 2)){
    		exist = 1;
    		break;
    	}
    }
    if (exist == 1){
    	printf("Majorant est %d.\n", nb);
    } else {
    	printf("Pas de majorant\n");
    }
}

void create(std::vector<int> &v) {
	for(int i = 0; i < v.size(); i++){
    	v[i] = (rand()%3);
    }
}

void affiche(const std::vector<int> v) {
	for(int i = 0; i < v.size(); i++){
    	std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
	srand(time(NULL));
/*	std::vector<int> v(20);
	create(v);
	affiche(v);
    detect1(v);
    detect2(v);
 */   
	
	



	return 0;
}