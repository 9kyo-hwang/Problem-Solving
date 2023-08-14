#include <bits/stdc++.h>

using namespace std;

vector<int> v;

void post_order(int left, int right) {
    if(left == right) { // left sub tree의 root인 경우
        cout << v[left] << "\n";
        return;
    }
    else if(left >= right) // 더이상 right가 없는 경우
        return;
    else {
        int index = left + 1;
        while(v[left] > v[index] && index <= right) // sub left tree 구간 끝 탐색
            index++;
        
        post_order(left + 1, index - 1); // left sub tree
        post_order(index, right); // right sub tree
        cout << v[left] << "\n"; // print root
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;

    while(cin >> n)
        v.push_back(n);

    post_order(0, v.size() - 1);

    return 0;
}