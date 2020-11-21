# Compiler
C_CPP := g++

# Compilation options
CPP_FLAGS := --std=c++98 -Wall -Wextra -pedantic -ggdb -Wno-unused-parameter -Wno-return-type -Wno-variadic-macros

# Compilation rules

main : graph.o main.o tas.o tasid.o
	$(C_CPP) $(CPP_FLAGS) -o $@ $^	

%.o : %.cpp %.hpp
	$(C_CPP) $(CPP_FLAGS) -o $@ -c $< 

clean:
	rm *.o main
