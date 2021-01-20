#include <stdio.h>

int main()
{
    int n, cnt;
    scanf("%d", &n);
    
    if(n==4 || n==7){
        printf("-1");
        return 0;
    }
    
    if(n%5==0) cnt=n/5;
    else if(n%5==1 || n%5==3) cnt=n/5+1;
    else cnt=n/5+2;

    printf("%d", cnt);
}