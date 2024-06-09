// 207404997
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WEIGHT 20
#define ITEMS 5

int max(int a, int b) {
    if(a>b) return a;
    return b;
}

int knapSack(int weights[], int values[], int selected_bool[]){
    int dp[ITEMS+1][MAX_WEIGHT+1];
    for(int i=0; i<=ITEMS; i++) dp[i][0] = 0;
    for(int j=0; j<=MAX_WEIGHT; j++) dp[0][j] = 0;
    for(int i=1; i<=ITEMS; i++){
        for(int j=1; j<=MAX_WEIGHT; j++){
            if(j-weights[i-1] < 0){
                dp[i][j] = dp[i-1][j];
            }
            else{
                int without_i = dp[i-1][j];
                int with_i = dp[i-1][j-weights[i-1]]+values[i-1];
                dp[i][j] = max(without_i, with_i);
            }
        }
    }
    /*printf("X  ");
    for(int i=0; i<=MAX_WEIGHT; i++){
        printf("%d ",i);
        if(i<10) printf(" ");
    }
    printf("\n");
    for(int i=0; i<=ITEMS; i++){
        printf("%d ", i);
        if(i<10) printf(" ");
        for(int j=0; j<=MAX_WEIGHT; j++){
            printf("%d ", dp[i][j]);
            if(dp[i][j]<10) printf(" ");
        }
        printf("\n");
    }*/
    int i = ITEMS, j = MAX_WEIGHT;
    while(i>0 && j>=0){
        if(dp[i-1][j] != dp[i][j]){
            selected_bool[i-1] = 1;
            j -= weights[i-1];
            i--;
        } else i--;
    }
    return dp[ITEMS][MAX_WEIGHT];
}

int main(){
    int weights[ITEMS];
    int values[ITEMS];
    char *items[ITEMS];
    int bool[ITEMS]={0};
    for(int i=0; i<ITEMS; i++){
        items[i] = (char *)malloc(100 * sizeof(char));
        //printf("enter name for item %d: ",i+1);
        scanf("%s", items[i]);
        //printf("enter value for item %d: ",i+1);
        scanf("%d", &values[i]);
        //printf("enter weight for item %d: ",i+1);
        scanf("%d", &weights[i]);
    }
    int m = knapSack(weights, values, bool);
    printf("a1Maximum value: %dz1\n", m);
    int count = 0;
    for(int i=0; i<ITEMS; i++){
        if(bool[i]==1) count++;
    }
    char*ans[count];
    int j = 0;
    for(int i=0; i<ITEMS; i++){
        if(bool[i]==1) ans[j++] = items[i];
    }
    printf("Selected items:");
    for(int i=0; i<j-1; i++){
        printf(" %s",ans[i]);
    }
    return 0;
}
