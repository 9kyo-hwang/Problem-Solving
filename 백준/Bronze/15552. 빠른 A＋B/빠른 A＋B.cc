#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;
    
    int a, b;
    while(T--) {
        cin >> a >> b;
        cout << a + b << "\n";
    }
    
    return 0;
}