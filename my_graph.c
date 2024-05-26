#include <stdio.h>
#include "my_mat.h"
#include "my_mat.c"

int main(){
    int testCase1[N][N] = {
            {0,1,0,4},
            {1,0,1,0},
            {0,1,0,1},
            {4,0,1,0}
    };
    int matrix[N][N], D[N][N], P[N][N];
    char input;
    printf("choose:\nA) input new matrix\nB) check if path exists\nC) find shortest path\nD or EOF) quit\nF) demo\nnode numbers are 0-9\n");
    while (true){
        printf("input: ");
        scanf(" %c", &input);
        if(input == 'E'){
            scanf("%c", &input);
            if(input=='O'){
                scanf("%c", &input);
                if(input=='F') input = 'D';
            }
        }
        if(input == 'D'){
            printf("goodbye\n");
            break;
        }
        if(input == 'A'){
            inputValues(matrix);
            floydWarshall(matrix, D, P);
        }
        if(input == 'B'){
            existsPath(D);
        }
        if(input == 'C'){
            shortestPath(P);
        }
        if(input == 'F'){
            autoLoad(matrix, testCase1);
            floydWarshall(matrix, D, P);
        }
    }
}