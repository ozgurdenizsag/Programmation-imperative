TDM_NUMBER := 05

##
## 	DEFAULT BUILD
##  --> help
## 

help :
	@echo "v m f -> (compile and) run test_vector, test_matrix, test_factorize_lu"
	@echo "t_v t_m t_f -> compare with expected results "
	@echo "m_v m_m m_f -> memory test"
	@echo "upload -> upload.tgz archive"

##
## 	COMPILATION
## 


# Compiler
C_CPP := g++

# Compilation options
CPP_FLAGS := --std=c++98 -Wall -Wextra -pedantic -ggdb -Wno-unused-parameter -Wno-return-type -Wno-variadic-macros

# Compilation rules


test_vector : test_vector.o vector.o
	$(C_CPP) $(CPP_FLAGS) -o $@ $^	

test_matrix : test_matrix.o vector.o matrix.o
	$(C_CPP) $(CPP_FLAGS) -o $@ $^	

test_factorize_lu : test_factorize_lu.o vector.o matrix.o factorize_lu.o
	$(C_CPP) $(CPP_FLAGS) -o $@ $^	

test_%.o : test_%.cpp %.hpp
	$(C_CPP) $(CPP_FLAGS) -o $@ -c $< 

%.o : %.cpp %.hpp
	$(C_CPP) $(CPP_FLAGS) -o $@ -c $< 

clean:
	rm *.o


##
## 	TEST
##


#
# Run
#

v : test_vector
	./test_vector

m : test_matrix
	./test_matrix

f : test_factorize_lu
	./test_factorize_lu


#
# Compare
#

OUTPUT_SUFFIX := _output.txt
EXPECTED_SUFFIX := _exepected.txt


# short call
t_v : t_vector
t_m : t_matrix
t_f : t_factorize_lu

t_% : test_%
	./test_$* > test_$*$(OUTPUT_SUFFIX)
	if diff test_$*$(EXPECTED_SUFFIX) test_$*$(OUTPUT_SUFFIX) ; then echo "OK" ; fi


##
## 	MEMORY CHECK
##

VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all


# short call
m_v : m_vector
m_m : m_matrix
m_f : m_factorize_lu

# WARNING 
# might be an extra (depending on the g++ version) 
# 72,704 bytes in 1 blocks are still reachable in loss record 1 of 1
# due to library std

m_% : test_%
	valgrind $(VALGRIND_FLAGS) ./test_$*  >/dev/null


##
## 	EXTRA DEPENDEDNCIES
##

matrix.o : vector.hpp
test_matrix.o : vector.hpp


factorize_lu.o : vector.hpp matrix.hpp
test_factorize_lu.o : vector.hpp vector.hpp matrix.hpp factorize_lu.hpp




##
## 	BUILD ARCHIVE TO SUBMIT
##

TDM_DIR := TDM_$(TDM_NUMBER)
TGZ_FILES :=  *.c *.h ?akefile cr.pdf

upload :
	[ -e cr.pdf ] || echo > cr.pdf
	cd .. ; tar czf $(TDM_DIR)/upload.tgz $(TGZ_FILES:%=$(TDM_DIR)/%)


