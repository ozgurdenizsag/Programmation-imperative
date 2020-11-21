# include <iostream>
# include <stdlib.h>  // drand48

# include <assert.h>

# undef NDEBUG

# include "matrix.hpp"

using namespace std ; 


Matrix :: Matrix() {
	line_nbr = 0;
	column_nbr = 0;
	element = NULL;
}					


Matrix :: Matrix ( unsigned int const _line_nbr , unsigned int const _column_nbr ) { 
	line_nbr = _line_nbr;
	column_nbr = _column_nbr;
	element = NULL;
} 


Matrix :: Matrix ( Matrix const & m ) { 
	line_nbr = m.line_nbr;
	column_nbr = m.column_nbr;
	for (int i = 0; i < (int) (line_nbr*column_nbr); ++i){
		element[i] = m.element[i];
	}
} 

Matrix :: ~ Matrix () {
  delete [] element ; // works with NULL
}


void Matrix :: init_alea () {
	for ( unsigned int i = 0 ; i < (line_nbr*column_nbr) ; i++ ) {	
    	element[i] = drand48 () ; 
  	}	
}


void Matrix :: init ( float const * coefficients ) {
	for ( unsigned int i = 0 ; i < (line_nbr*column_nbr) ; i++ ) {	
    	element[i] = coefficients[i];
  	}	
}


void Matrix :: set_identity () { 
	assert (line_nbr == column_nbr);
	for (int i = 0; i < (int) line_nbr; ++i){
		for (int j = 0; j < (int) column_nbr; ++j){
			if (i == j) {
				element[ (i)*line_nbr + j ] = 1;
			}else{
				element[ (i)*line_nbr + j ] = 0;
			}
		}
	}

}


std :: ostream & operator << ( std :: ostream & ost ,Matrix const & m ) { 
	ost << "\n";
	for (int i = 0; i < (int) line_nbr; ++i){
		ost << "|";
		for (int j = 0; j < (int) column_nbr; ++j){
			ost << "\n";
		}
	}
	for (int i = 0; i <(int) v.size; ++i){
		ost << v.element[i];
		if ( i != (int) v.size-1){
			ost << ",";
		}
	}
	ost << "]\n";
  return ost ; 
}


Matrix & Matrix :: operator = ( Matrix const & m ) { 
}


Matrix Matrix :: operator + ( Matrix const & m ) const { 
}


Matrix Matrix :: operator - ( Matrix const & m ) const { 
}


Matrix Matrix :: operator * ( Matrix const & m ) const { 
}


Vector Matrix :: operator * ( Vector const & v ) const { 
}


Matrix Matrix :: operator * ( const float a ) const { 
}


Matrix operator * ( float const a ,
		    Matrix const & m ) {
  return m * a ; 
}


Matrix & Matrix :: operator += ( Matrix const & m ) { 
}


Matrix & Matrix :: operator *= ( Matrix const & m ) { 
}


bool Matrix :: operator == ( Matrix const & m ) const { 
  return false ;
}


Vector Matrix :: extract_ligne ( unsigned int const l ,
				 unsigned int const c1 ,
				 unsigned int const c2 ) const { 
  return * ( Vector * ) NULL ;
}


Vector Matrix :: extract_col ( unsigned int const l1 ,
			       unsigned int const l2 ,
			       unsigned int const c ) const { 
  return * ( Vector * ) NULL ;
} 


Matrix Matrix :: extract_triangular_lower_diag_one () const { 
  return * ( Matrix * ) NULL ;
}


Matrix Matrix :: extract_triangular_upper_diag () const { 
  return * ( Matrix * ) NULL ;
}


Matrix Matrix :: extract_diagonal () const { 
  return * ( Matrix * ) NULL ;
}

