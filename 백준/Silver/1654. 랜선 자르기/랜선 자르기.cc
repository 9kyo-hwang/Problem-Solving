#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int K, N;
    cin >> K >> N;

    long long max_len = 0;
    vector<long long> line(K);
    for(auto &i : line) {
        cin >> i;
        if(i > max_len)
            max_len = i;
    }

    long long start = 1, end = max_len, div_max = 0;
    while(start <= end) {
        auto mid = (start + end) / 2;

        long long count = 0;
        for(auto i : line)
            count += i / mid;

        if(count < N) end = mid - 1;
        else {
            if(mid > div_max)
                div_max = mid;

            start = mid + 1;
        }
    }

    cout << div_max;

    return 0;
}