CC = gcc
FLAGS = -Wall -g

.PHONY: all clean

all: my_graph

clean:
	rm -f *.o *.a *.so c my_graph my_Knapsack

my_graph: my_graph.c
	$(CC) -o my_graph my_graph.c