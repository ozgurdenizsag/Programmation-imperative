# ifndef __MATRIX_HPP
# define __MATRIX_HPP


# include <sstream>
# include <assert.h>


# include "vector.hpp"


# undef NDEBUG


/* !
 * \brief This module is made to handle (bi-dimensional) matrix of floats. 
 * 
 * \author PASD
 * \date 2016
 */


class Matrix {

  /*! Number of lines */
  unsigned int line_nbr ;

  /*! Number of columns */
  unsigned int column_nbr; 

  /*! All the elements of the matrix stored in a 1-D array of floats. */
  float * element ; 
 
public:
  /*! To construct an empty, zero by zero matrix (element is then NULL). */
  Matrix ();
  
  /*! To construct a _line_nbr by _column_nbr matrix filled with zeros. */
  Matrix ( unsigned int const _line_nbr ,
	   unsigned int const _column_nbr ) ;

  /*! Copy construct. */
  Matrix ( Matrix const & m ) ; 

  /*! Destructor */
  ~ Matrix () ;
 
  /*! To access the number of lines. */
  unsigned int get_line_nbr () const {
    return line_nbr ;
  } ; 

  /*! To access the number of columns. */
  unsigned int get_column_nbr () const {
    return column_nbr;
  } ;
 
  /*! To access any element of the matrix.
   * \param column Column number
   * \param line Line number
   * \return A reference to the element at position (column,line).
   */
  float & operator () ( unsigned int const line, unsigned int const column ) {
    assert ( line < line_nbr ) ;
    assert ( column < column_nbr ) ;
    return element [ line * column_nbr + column ] ; 
  } ; 

  /*! To access any element of the matrix (const version).
   * \param column Column number
   * \param line Line number
   * \return A reference to the element at position (column,line).
   */
  float const & operator () ( unsigned  int const line ,
			      unsigned  int const column ) const {
    assert ( line < line_nbr ) ;
    assert ( column < column_nbr ) ;
    return element [ line * column_nbr + column ] ; 
  } ; 

  /* To fill the matrix with random values.
   */
  void init_alea () ; 

  /*! Initialize the matrix with the value in the array
   * \param coefficients Pointer tot the values.
   * \pre The array should have Impossible to test) 
   */
  void init ( float const * coefficients ) ; 
  
  /*! Initialize the matrix as the identity matrix (1 in the diagonal, 0 everywhere else).
   * \pre must be a square matrix.
   */
  void set_identity () ; 
 
  /*! Sum operator.
   * \param m Matrix to add the value of.
   * \pre The two matrices should have the same size.
   * \return A new Matrix whose coordinates are the sum of the coordinate of this and m.
   */
  Matrix operator + ( Matrix const & m ) const ; 

  /*! Minus operator.
   * \param m Matrix to subtract the value of.
   * \pre The two matrices should have the same size.
   * \return A new Matrix whose coordinates are the coordinate of this minus the coordinates of m.
   */
  Matrix operator - ( Matrix const & m ) const ; 

  /*! Matrix-matrix multiplication operator.
   * \param m Matrix to multiply by.
   * \pre The number of columns of this should be equal to the number of lines of m.
   * \return A new Matrix whose coordinates are the scalar product of lines of this and column of m.
   */
  Matrix operator * ( Matrix const & m ) const ; 

  /*! Matrix-vector multiplication operator.
   * \param v Vector to multiply by.
   * \pre The number of columns of this should be equal to the dimension of v.
   * \return A new Vector whose coordinates are the scalar product of lines of this and v.
   */
  Vector operator * ( Vector const & v ) const ; 

  /*! Compute the product of the matrix by a scalar a.
   * \param a Float to multiply by.
   * \return A new matrix whose coordinates are the product of the coordinate of this and a.
   */
  Matrix operator * ( float const a ) const ; 

  /*! Affectation operator.
   * \param m Matrix to copy.
   * \return The matrix it-self as a reference
   */ 
  Matrix & operator = ( Matrix const & m ) ; 

  /*! Modify the matrix by adding another one.
   * \param m Matrix to add to.
   * \pre The two matrices should have the same size.
   * \return The matrix it-self as a reference
   */ 
  Matrix & operator += ( Matrix const & m ) ; 

  /*! Modify the matrix by multiplying by another one.
   * \param m Matrix to multiply by.
   * \pre The number of columns of this should be equal to the number of lines of m.
   * \return The matrix it-self as a reference
   */ 
  Matrix & operator *= ( Matrix const & m ) ; 
 
  /*! Test whether two matrices are coefficient-wise equel.
   * \param m Matrix to compare to.
   * \pre They should have the same dimension.
   * \return true if the matrix are equal.
   */ 
  bool operator == ( Matrix const & m ) const ; 
 
  /*! To extract a vector.
   * \param l Line to extract. 
   * \param c1 First column to extract.
   * \param c2 Last column to extract.
   * \pre arguments are valid.
   * \pre c1 <= c2.
   * \return An extracted copy.
   */
  Vector extract_ligne ( unsigned int const l ,
			 unsigned int const c1 ,
			 unsigned int const c2 ) const ; 
  /*! To extract a vector.
   * \param l1 First line to extract. 
   * \param l2 Last line to extract. 
   * \param c column to extract.
   * \pre arguments are valid.
   * \pre l1 <= l2.
   * \return An extracted copy.
   */
  Vector extract_col ( unsigned int const l1 ,
		       unsigned int const l2 ,
		       unsigned int const c ) const ; 

  /*! Extract a matrix that is equal under the diagonal, one on the diagonal and zero everywhere else. 
   * \pre must be a square matrix.
   */
  Matrix extract_triangular_lower_diag_one () const ;
  
  /*! Extract a matrix that is equal above the diagonal and the diagonal and zero everywhere else.
   * \pre must be a square matrix.
   */
  Matrix extract_triangular_upper_diag () const ; 

  /*! Extract a matrix that is equal on the diagonal and zero everywhere else. 
   * \pre must be a square matrix.
   */
  Matrix extract_diagonal () const ; 

  
  friend Matrix operator * ( float const a ,
			     Matrix const & m ) ; 

  friend std::ostream & operator << ( std::ostream& ost ,
				      Matrix const & m ) ; 
} ; 


/*!
 * This function computes the decomposition L U (lower upper) of a square matrix.
 * After the call, Matrix m will hold L in the upper part and U in the lower part.
 */
void factorize_lu ( Matrix & m ) ; 


/*! Compute the product of the matrix by a scalar a.
 * \param a Float to multiply by.
 * \param m Matrix to multiply.
 * \return A new matric whose coordinates are the product of the coordinate of m and a.
 */
Matrix operator * ( float const a ,
		    Matrix const & m ) ; 


/*! Print a string version of the Matrix to a stream. 
 * \param ost Output stream to write to.
 * \param m Matrix to print.
 * \return The output stream.
 */
std::ostream & operator << ( std::ostream& ost ,
			     Matrix const & m ) ; 


# endif
