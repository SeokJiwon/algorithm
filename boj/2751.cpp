#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num,tmp;
    vector<int> v;
    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(),v.end());

    for(int i = 0; i < num; i++){
        cout << v[i] << '\n';
    }
}