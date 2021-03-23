#include <stdio.h>
#include <stdlib.h>

void buildList(int A[], int n){
    for(int r=0;r<n;r++){
        A[r]=r+1;
    }
}

void removed(int A[], int n, int r){
    for(int i=r;i<r-1;r++){
        A[i]=A[i+1];
    }
}

int runSimulation(int A[], int n, int k){
    int r = 0;
    while(n>1){
        r=(r+k)%n;
        removed(A, n, r);
        n=n-1;
        }
    return A[r];
}

int candle(int n, int k){
    int A[n];
    buildList(A, n);
    int idx = runSimulation(A, n, k);
    return idx;
}

int main()
{
    int num = candle(7,3);
    printf("%d", num);
}
