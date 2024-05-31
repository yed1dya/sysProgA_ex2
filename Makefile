# 207404997
CC = gcc
FLAGS = -Wall -g

.PHONY: all clean

all: my_graph my_Knapsack

clean:
	rm -f *.o *.a *.so c my_graph my_Knapsack

my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAGS) -c -fPIC my_Knapsack.c

my_Knapsack: my_Knapsack.o
	$(CC) -o my_Knapsack my_Knapsack.o

my_graph.o: my_graph.c
	$(CC) $(FLAGS) -c -fPIC my_graph.c

my_graph: my_graph.o
	$(CC) -o my_graph my_graph.o

my_mat.o: my_mat.h
	$(CC) $(FLAGS) -fPIC my_mat.c
