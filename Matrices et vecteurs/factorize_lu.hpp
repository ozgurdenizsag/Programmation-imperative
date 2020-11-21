# ifndef __FACTORIZE_LU_HPP
# define __FACTORIZE_LU_HPP




# include "matrix.hpp"



/* !
 * \brief This module provide a function to compute the L U decomposition of any square matrix.. 
 * 
 * \author PASD
 * \date 2016
 */



/*!
 * This function computes the decomposition L U (lower upper) of a square matrix.
 * After the call, Matrix m will hold L in the upper part and U in the lower part.
 * \pre m is square
 */
void factorize_lu ( Matrix & m ) ; 


# endif
