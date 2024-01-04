#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;

    string str;
    cin >> str;

    long long r = 1;
    int M = 1234567891;

    long long H = 0;

    for(char c : str) {
        H = (H + (c - 'a' + 1) * r) % M; // a * r mod M
        r = (r * 31) % M; // 31 ^ r, modular prime number
    }

    cout << H;

    return 0;
}