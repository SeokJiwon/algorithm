#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool vps(string ps) {
    stack<char> s;
    bool tmp = true;
    for (int i = 0; i < ps.size(); ++i) {
        if (ps[i] == '(')
            s.push(ps[i]);
        else if (!s.empty() && ps[i] == ')')
            s.pop();
        else if (s.empty() && ps[i] == ')') {
            tmp = false;
            break;
        }
    }
    if (s.empty() && tmp) 
        return true;
    else 
        return false;
}
int main() {
    int N;
    string ps;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> ps;
        if (vps(ps)) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}
