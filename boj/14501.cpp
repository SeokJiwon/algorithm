#include <stdio.h>

int n, t[17], p[17], d[17], res;

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }
    for(int i=1; i<=n; i++){
        if(i+t[i] <=n+1){
            d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]);
            res = max(res, d[i+t[i]]);
        }

        d[i+1] = max(d[i+1], d[i]);
        res = max(res, d[i+1]);
    }
    printf("%d\n", res);
}