// 207404997
#include <stdio.h>
#include "my_mat.h"

void floydWarshall(int W[N][N], int D[N][N], int P[N][N]){
    for(int i=0; i<N; i++) {
        for (int j = 0; j < N; j++) {
            //printf("%d ", W[i][j]);
            D[i][j] = W[i][j];
            P[i][j] = W[i][j]==0 ? -1 : i;
        }
        //printf("\n");
    }
    //printf("\n");
    for(int i=0; i<N; i++) {
        for (int j = 0; j < N; j++) {
            //printf("%d ", P[i][j]);
        }
       // printf("\n");
    }
    //printf("\n");
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(i!=j && D[i][k]!=0 && D[k][j]!=0 && (D[i][j]==0 || D[i][j] > D[i][k]+D[k][j])){
                    D[i][j] = D[i][k]+D[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
    }
    /*for(int i=0; i<N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }*/
}

void inputValues(int matrix[N][N]){
    int input;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            //printf("edge (%d, %d): ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void existsPath(int D[N][N]){
    int i, j;
    //printf("enter source node: ");
    scanf("%d", &i);
    //printf("enter target node: ");
    scanf("%d", &j);
    printf("%s", D[i][j]>0 ? "True\n" : "False\n");
}

void printPath(int P[N][N], int i, int j){
    /*if(i == j) printf("%d ", i);
    else if(P[i][j] == -1) printf("no path");
    else{
        printPath(P, i, P[i][j]);
        printf("%d ", j);
    }*/
    if (P[i][j] != 0){
        printf("%d\n", P[i][j]);
    }
    else printf("-1\n");
    return 0;
}

void shortestPath(int P[N][N]){
    int i, j;
    //printf("enter source node: ");
    scanf("%d", &i);
    //printf("enter target node: ");
    scanf("%d", &j);
    //if(i==j) printf("same node");
    printPath(P, i, j);
    //printf("\n");
}

void autoLoad(int matrix[N][N], int source[N][N]){
    for(int i=0; i<N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = source[i][j];
        }
    }
}
