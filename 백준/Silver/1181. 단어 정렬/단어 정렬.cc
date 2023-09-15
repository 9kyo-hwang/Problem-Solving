#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin >> N;

    vector<string> v(N);
    for(auto & str : v)
        cin >> str;

    sort(v.begin(), v.end(),
         [](const string& s, const string& t) {
        return s.length() < t.length() || s.length() == t.length() && s < t;
    });
    
    v.erase(unique(v.begin(), v.end()), v.end());

    for(const auto& str : v)
        cout << str << "\n";

    return 0;
}