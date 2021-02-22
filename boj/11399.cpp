#include <iostream>
#include <algorithm>
using namespace std;

int N, ans=0;
int P[1000]={0,};

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> P[i];
    }
    sort(P, P+N);
    for(int i=0; i<N; i++){
        ans+=P[i]*(N-i);
    }
    cout << ans << ' '; 
}