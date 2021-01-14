#include <iostream>
 
const long long p = 1000000007;
long factorial[4000000];
long x_after, x_before, temp, q;
 
void euclidean(long p,long b) {
    if (p%b > 0) {
        euclidean(b, p%b);
        temp = x_after;
        x_after = x_before - (p/b)*x_after;
        x_before = temp;
    }
    else {
        x_after = 1;
        x_before = 0;
    }
}
 
int main() {
    int n, k;
    std::cin >> n >> k;
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i <= n; i++) 
        factorial[i] = (factorial[i - 1] * i) % p;
 
    long b = (factorial[k] * factorial[n - k]) % p;
 
    euclidean(p, b);
    long result = ((factorial[n] % p)* (x_after%p)) % p;
    if (result < 0) result += p;
    std::cout << result << std::endl;
}
