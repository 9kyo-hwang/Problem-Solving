#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define MAX 4000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v;
    int num_count[2 * MAX + 1]; // -4000 ~ 4000 -> 0 ~ 8000
    for(int i = 0; i < 2 * MAX + 1; i++)
        num_count[i] = 0;

    int n;
    for(int i = 0; i < N; i++) {
        cin >> n;
        v.push_back(n);
        num_count[n + MAX]++;
    }

    sort(v.begin(), v.end());

    double average = 0.0, median = 0.0, mode = 0.0, range = 0.0;

    // 1. 평균
    for(int i = 0; i < N; i++)
        average += v[i];
    average = round(average / N);
    if(average > -numeric_limits<float>::epsilon() && average < numeric_limits<float>::epsilon())
        average = 0;
    
    // 2. 중앙값
    median = v[N / 2];

    // 3. 최빈값
    int max_index = 0;
    for(int i = 1; i < 2 * MAX + 1; i++) {
        if(num_count[i] > num_count[max_index])
            max_index = i;
    }

    for(int i = max_index + 1; i < 2 * MAX + 1; i++) {
        if(num_count[i] == num_count[max_index]) {
            max_index = i;
            break;
        }
    }

    mode = max_index - MAX;

    // 4. 범위(최대값 - 최소값)
    range = v[N - 1] - v[0];

    cout << average << "\n" << median << "\n" << mode << "\n" << range << "\n";
    return 0;
}