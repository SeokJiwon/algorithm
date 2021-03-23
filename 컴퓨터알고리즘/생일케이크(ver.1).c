#include <stdio.h>
#include <stdlib.h>

void buildList(int A[], int n){
    for(int r=0;r<n;r++){
        A[r]=r+1;
    }
}

int runSimulation(int A[], int n, int k){
    int r = 0;
    int N = n;
    while(n>1){
        int i=0;
        while(i<k){
            r=(r+1)%N;
            if (A[r]!=0){
                i=i+1;
            }
        }
        A[r]=0;
        n=n-1;
        while(A[r]==0){
            r=(r+1)%N;
        }
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
