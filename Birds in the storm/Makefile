# compilateur
CC := g++
# options de compilation
CFLAGS := -std=c++98 -Wall -Wextra -pedantic -ggdb 

# règle de compilation --- exécutables
all : main

main : main.o ennemi.o oiseau.o plateau.o
	$(CC) $(CFLAGS) -o $@ $^	

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

# options de compilation
clean:
	rm *.o main
