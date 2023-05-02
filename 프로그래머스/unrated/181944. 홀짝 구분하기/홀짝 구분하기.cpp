#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    cout << n << " ";
    cout << (n % 2 == 0 ? "is even" : "is odd"); 
    return 0;
}