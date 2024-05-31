# 207404997
CC = gcc
FLAGS = -Wall -g

.PHONY: all clean

all: my_graph my_Knapsack

clean:
	rm -f *.o *.a *.so c my_graph my_Knapsack

my_graph: my_graph.c
	$(CC) -o my_graph my_graph.c

my_Knapsack: my_Knapsack.c
	$(CC) -o my_Knapsack my_Knapsack.c
