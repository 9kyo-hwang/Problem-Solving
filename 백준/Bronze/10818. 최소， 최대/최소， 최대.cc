#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin >> N;

    int n;
    int max = -1000001, min = 1000001;
    for(auto i = 0; i < N; i++) {
        cin >> n;

        if(n < min) min = n;
        if(n > max) max = n;
    }

    cout << min << " " << max;

    return 0;
}