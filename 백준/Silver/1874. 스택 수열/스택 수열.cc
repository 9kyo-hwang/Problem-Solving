#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v(N); // sequence of popped
    for(auto &i : v)
        cin >> i;
    
    stack<int> s; // number stack
    queue<char> q; // operator queue
    int i = 0;
    for(auto n = 1; n <= N; n++) {
        s.emplace(n);
        q.emplace('+'); // push

        while(!s.empty() && s.top() == v[i]) { // pop number
            s.pop();
            q.emplace('-'); // popped
            i++;
        }
    }

    if(!s.empty()) cout << "NO";
    else {
        while(!q.empty()) {
            cout << q.front() << "\n";
            q.pop();
        }
    }

    return 0;
}