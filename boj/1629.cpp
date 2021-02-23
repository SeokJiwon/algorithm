#include <iostream>
#include <algorithm>
using namespace std;
#define lli long long int
 
lli a, b, c;

lli calc(lli x, lli y) {
    if (y == 0)
        return 1;
    else if (y == 1)
        return x;
    if (y % 2 > 0)
        return calc(x, y - 1)*x;
    lli half = calc(x, y / 2);
    half %= c;
    return (half * half) % c;
}
 
int main() {
    cin >> a >> b >> c;
    cout << calc(a,b)%c << ' ';
}
