
# include <assert.h>

# include "matrix.hpp"

using namespace std ; 


# define SIZE 5

  
int main ( void ) {

  // Tests sur les opérateurs
  Matrix m1 ( SIZE , SIZE ) ; 
  float tab [ SIZE * SIZE ] = { 4 , 1 , 2 , 3 , 4 , 4 , 3 , 3 , 6 , 5 , 8 , 12 , 12 , 22 , 16 , 12 , 5 , 13 , 16 , 21 , 8 , 10 , 17 , 23 , 25} ; 
  m1 . init ( tab ) ; 
 
  Matrix m2 ( SIZE , 2 * SIZE ) ; 
  m2 . init_alea () ; 

  cout << "Matrice M1 :" << endl ; 
  cout << m1 ; 
  cout << "Matrice M2 :" << endl ; 
  cout << m2 ; 

  cout << "Product of M2 by all basis vectors:" << endl ;
  for ( int i = 0 ; i < 2 * SIZE ; i ++ ) {
    Vector v ( 2 * SIZE ) ;
    v [ i ] = 1 ;
    cout << m2 * v ;
  }

  cout << "Produit de M1 et M2 :" << endl ; 
  cout << m1 * m2 ;

  Matrix id ( SIZE , SIZE ) ;
  id.set_identity () ; 

  cout << "M1 == M1 |- " << ( m1 == m1 ) << endl ;
  cout << "M1 == 2 * M1 |- " << ( m1 == 2 * m1 ) << endl ;
  cout << "M1 * M2 == M1 * M2 |- " << ( m1 * m2 == m1 * m2 ) << endl ;

  cout << "M1 + 2 fois l'identité :" << endl ; 
  cout << m1 + 2 * id ; 

  return 0 ; 
}
