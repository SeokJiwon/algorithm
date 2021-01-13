#include <stdio.h>

int main()
{
    int n, k;
    int cnt=0;
    int money[10]={0,};
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i=0;i<=n-1;i++){
        scanf("%d", &money[i]);
    }
    for(int j=9;j>=0;j--){
        if(money[j]==0) continue;
        if(k/money[j]==0) continue;
        else{
            int tmp=k/money[j];
            k=k%money[j];
            cnt+=tmp;
        }
    }
    printf("%d", cnt);
}