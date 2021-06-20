#include <iostream>
#include <algorithm>
using namespace std;

int K, N;
long long arr[10001];

bool check(long long len){
    int cnt = 0;
    for(int i=0; i<K; i++){
        cnt += arr[i]/len;
    }
    if(cnt >= N) return true;
    return false;
}

int main(){
    long long high = 0;
    long long result = 0;
    long long low = 1;
    
    cin >> K >> N;
    for(int i=0 ; i<K ; i++){
        cin >> arr[i];
        high = max(high, arr[i]);    
    }

    while(low <= high){
        long long mid = (low + high) / 2;
        if(check(mid)){
            if(result < mid) result = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    cout << result;
}