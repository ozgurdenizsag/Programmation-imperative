# include <stdlib.h>
# include <assert.h>
# include "vector.hpp"

using namespace std ; 

Vector :: Vector ( ) {
	(*this).size=0;
	(*this).element=NULL;
}

Vector :: Vector ( unsigned int const _size ) {
	(*this).size = _size;
	(*this).element = new float[_size]();
}

Vector :: Vector ( const Vector & v ) {
	(*this).size = v.size;
	(*this).element = new float[v.size]();
	for (int i = 0; i < (int)v.size; ++i){
		(*this).element[i] = v[i];
	}
}


Vector :: ~Vector () { 
}


void Vector :: init_alea () { 
  for ( unsigned int i = 0 ; i < size ; i++ ) {	
    element[ i ] = drand48 () ; 
  }					
}


float & Vector :: operator [] ( unsigned int const i ) { 
	assert ( i < (*this).size ) ;
	return (*this).element[i];
}


float const & Vector :: operator [] ( unsigned int const i ) const { 
  	assert ( i < (*this).size ) ;
	return (*this).element[i];
}


std :: ostream & operator << ( std :: ostream& ost, Vector const & v ) { 
	ost << "\n[";
	for (int i = 0; i <(int) v.size; ++i){
		ost << v.element[i];
		if ( i != (int) v.size-1){
			ost << ",";
		}
	}
	ost << "]\n";
  return ost ; 
}


Vector & Vector :: operator = ( Vector const & v ) { 
	delete[](*this).element;
	(*this).size = v.size;
	(*this).element = new float[v.size]();
	for (int i = 0; i < (int)v.size; ++i){
		(*this).element[i] = v[i];
	}
  	return ( *this ) ; 
}


Vector Vector :: operator + ( Vector const & v ) const { 
	assert ( v.size == (*this).size );
	Vector res(v.size);
	for (int i = 0; i < (int) v.size; ++i){
		res.element[i] = (*this).element[i] + v.element[i];
	}
  	return res ;
}


Vector Vector :: operator - ( Vector const & v ) const { 
  	assert ( v.size == (*this).size );
	Vector res(v.size);
	for (int i = 0; i < (int) v.size; ++i){
		res.element[i] = (*this).element[i] - v.element[i];
	}
  	return res ;
}


Vector Vector :: operator * ( float const a ) const { 
  	assert ( a != 0 );
	Vector res((*this).size);
	for (int i = 0; i < (int) (*this).size; ++i){
		res.element[i] = (*this).element[i]*a;
	}
  	return res ;
}


float Vector :: operator | ( Vector const & v ) const { 
	assert ( v.size == (*this).size );
	float res = 0;
	for (int i = 0; i < (int) (*this).size; ++i){
		res += (*this).element[i] * v.element[i];
	}
  	return res ;
}


bool Vector :: operator == ( Vector const & v ) const { 
	assert ( v.size == (*this).size );
	for (int i = 0; i < (int) v.size; ++i){
		if ((*this).element[i] != v.element[i]){
			return false;
		}
	}
  	return true ;
}


Vector operator * ( float const a ,Vector const & v ) { 
  	return v*a;
}



