#include<iostream>
#include<algorithm>
using namespace std;
 
int arr[100001];
 
void BinarySearch(int n, int key){
    int start = 0;
    int end = n-1;
    int mid;
 
    while(end - start >= 0){
        mid = (start + end)/2;
 
        if(arr[mid] == key){
            printf("1\n");
            return ;
        }
        else if(arr[mid] > key) end = mid - 1;
        else    start = mid + 1;
    }
    printf("0\n");
    return ;
}
 
int main(){
    int N, M, tmp;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N); 
    cin >> M;
 
    for(int i=0; i<M; i++){
        cin >> tmp;
        BinarySearch(N, tmp);
    }
}