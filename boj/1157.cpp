#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string str;
    int arr[26] = {0,};
    int max_cnt = 0;
    int idx = 0;
    int count = 0;
    
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    for(int i=0;i<str.length();i++){
        arr[str[i]-'A']++;
    }
    for(int i=0;i<26;i++){
        if(arr[i]>max_cnt){
            max_cnt = arr[i];
            count = 0;
            idx=i;
        }
        if(max_cnt == arr[i])
            count++;
    }
    if(count > 1)
        cout << "?";
    else
        cout << (char)('A'+idx);
}