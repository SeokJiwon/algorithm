#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); // 시간초과 떠서 3줄 추가하니까 해결됨!
    int N;
    cin >> N;
    priority_queue<int> pq;
    while(N--){
        int x;
        cin >> x;
        if (x==0){
            if(pq.empty()){
                cout << "0" << "\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
}