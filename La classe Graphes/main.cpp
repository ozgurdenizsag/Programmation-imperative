#include "graph.hpp"
#include "tas.hpp"

int main() {

	Graph<string,int> *unSommet = new Graph<string,int>();
	unSommet->ajouterSommet("A");
	unSommet->ajouterArete("A", "B", 5);
	unSommet->ajouterArete("A", "G", 1);
	unSommet->ajouterArete("B", "A", 5); 
	unSommet->ajouterArete("B", "G", 2); 
	unSommet->ajouterArete("G", "A", 1);
	unSommet->ajouterArete("G", "B", 2);
	unSommet->ajouterArete("G", "E", 3); 
	unSommet->ajouterArete("G", "D", 32); 
	unSommet->ajouterArete("E", "G", 3); 
	unSommet->ajouterArete("E", "C", 7); 
	unSommet->ajouterArete("D", "G", 32); 
	unSommet->ajouterArete("D", "F", 5); 
	unSommet->ajouterArete("C", "F", 8); 
	unSommet->ajouterArete("C", "E", 7); 
	unSommet->ajouterArete("F", "C", 8); 
	unSommet->ajouterArete("F", "D", 5);

	//unSommet->afficher();
	

	unSommet->dijkstra(pair<string,int>("B",0));

	delete unSommet; 

/*
	vector<int> v = {1,7,75,50,15,8,9,20,25,-1};
	Tas<int> *unTas = new Tas<int>(v);
	unTas->afficher();
	unTas->ajouterElement(2);
	unTas->afficher();

	int min=unTas->extraireMin();
	cout << min << endl;
	
	delete unTas;
*/
/*

	pair<string,int> p1 = make_pair<string,int>("A",5);
	pair<string,int> p2 = make_pair<string,int>("B",3);
	pair<string,int> p3 = make_pair<string,int>("C",10);
	pair<string,int> p4 = make_pair<string,int>("C",4);
	pair<string,int> p5 = make_pair<string,int>("E",2);
	pair<string,int> p6 = make_pair<string,int>("F",1);

	
	Tasid<string,int> *monTasid = new Tasid <string,int>();
	monTasid->ajouterElement(p1);
	monTasid->ajouterElement(p2);
	monTasid->ajouterElement(p3);
	monTasid->ajouterElement(p4);
	monTasid->ajouterElement(p5);
	monTasid->ajouterElement(p6);

	monTasid->afficher();

	pair<string,int> p7 = monTasid->extraireMin();

	cout << p7.first << " " << p7.second << endl;
	monTasid->afficher();
	
*/


	
    return 0;
}
