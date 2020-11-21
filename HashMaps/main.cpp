#include "tablehashage.hpp"

int main() {

	TableHashage<int,string> *myTable = new TableHashage<int,string>();
	myTable->inserer(11,"Ozgur");
	myTable->inserer(12,"Deniz");
	myTable->inserer(13,"SAG");
	myTable->inserer(13,"Juliette");

	
	delete myTable;


    return 0;
}
