#include <stdio.h>

int main()
{
    int n, m, t;
    int DP[33][33]={0,};
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i=1;i<=m;i++){
            DP[1][i]=i;
        }
        for(int i=2;i<=n;i++){
            for(int j=2; j<=m;j++){
                DP[i][j]=DP[i-1][j-1]+DP[i][j-1];
            }
        }
        printf("%d\n", DP[n][m]);
    }
}