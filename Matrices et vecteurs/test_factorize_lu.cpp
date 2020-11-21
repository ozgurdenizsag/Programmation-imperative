
# include "matrix.hpp"
# include "factorize_lu.hpp"


using namespace std ; 



/*!
 * Compute the decomposition and check its validity.
 * \param n size of the matrix.
 * \param coefficients coefficients of the matrix.
 */
static void test_LU ( Matrix m ) {
  
  Matrix m_orig ( m ) ;
  cout << "Factorisation LU de :" << endl ; 
  cout << m ;
  
  factorize_lu ( m ) ;
  
  Matrix l = m . extract_triangular_lower_diag_one () ; 
  Matrix u = m . extract_triangular_upper_diag () ; 
  
  cout << "Matrix L :" << endl ; 
  cout << l ; 

  cout << "Matrix U :" << endl ; 
  cout << u ; 

  cout << "Vérification M1 - L*U = 0 : " ;
  Matrix m_verif = m_orig - l * u ;
  Matrix m_zero ( m . get_line_nbr () , m . get_line_nbr () ) ;
  if ( m_verif == m_zero ) {
    cout << "yes" << endl ;
  } else {
    cout << "NO!" << endl  << m_orig - ( l * u ) ;
  }
}


// To simplify writing to the maximum
# define TEST_LU( n , ... )				\
  {							\
    Matrix m ( n , n ) ;				\
    float coefficients [ n * n ] = { __VA_ARGS__ } ;	\
    m . init ( coefficients ) ;				\
    test_LU ( m ) ;					\
  }


int main ( void ) {
  TEST_LU ( 1 , 2 ) ;
  TEST_LU ( 2 , 2 , 1 , 2 , 3 ) ;
  TEST_LU ( 3 , 2 , 1 , 2 , 3 , 4 , 4 , 3 , 3 , 0 ) ;
  TEST_LU ( 4 , 2 , 1 , 2 , 3 , 4 , 4 , 3 , 3 , 0 , 5 , 1 , 2 , 1 , 0 , 5 , 8 ) ;
  TEST_LU ( 5 , 2 , 1 , 2 , 3 , 4 , 4 , 3 , 3 , 0 , 5 , 1 , 2 , 1 , 0 , 5 , 8 , 5 , 1 , 6 , 1 , 8 , 10 , 1 , 2 , 0 ) ;
  TEST_LU ( 6 , 2 , 1 , 2 , 3 , 4 , 4 , 3 , 3 , 0 , 5 , 1 , 2 , 1 , 0 , 5 , 8 , 5 , 1 , 6 , 1 , 8 , 10 , 1 , 2 , 0 , 16 , 12 , 5 , 13 , 16 , 2 , 8 , 10 , 7 , 3 , 25 ) ;
  return 0 ; 
}
