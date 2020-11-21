# include "vector.hpp"

# define SIZE 10
# define SCALAIRE 2.3

using namespace std ; 


int main ( int argc ,
	   const char * argv[] ) {
  Vector v1 ( SIZE ) ; 
  for ( unsigned int i=0 ; i < SIZE ; i++ ) {
    v1 [ i ] = i ;
  }
  cout << v1 ; 
 
  Vector v2 ( SIZE ) ; 
  v2.init_alea () ; 
  cout << v2 ; 
 
  Vector v3 = v1 + v2 ; 
  cout << v3 ; 
 
  Vector v4 = SCALAIRE * v1 ; 
  cout << v4 ; 

  cout << "v1 == v1 |- " << ( v1 == v1 ) << endl ;
  cout << "v1 == v2 |- " << ( v1 == v2 ) << endl ;
  cout << "v4 == v1 * " << SCALAIRE << " |- " << ( v4 == v1 * SCALAIRE ) << endl ;

  cout << ( v4 | v4 ) << endl; 

  return 0 ; 
}
