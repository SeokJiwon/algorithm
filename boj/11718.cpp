#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    while(true){
        getline(cin, s); // getline 함수: 한 줄을 입력받아 저장하는 함수
        if (s=="") break;
        cout << s << "\n";
    }
}