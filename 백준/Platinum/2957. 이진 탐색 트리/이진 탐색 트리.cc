#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    /*
     * 삽입되는 데이터 x의 높이 구하기
     * predecessor와 successor는 반드시 같은 서브트리에 존재한다.
     * predecessor와 successor는 반드시 부모-자식 관계이다.
     * x의 높이는 predecessor와 successor 중 더 높은 것 + 1이다.
     * x는 반드시 predecessor와 successor의 사이에 들어가게 되며,
     * 다시 말해 predecessor의 오른쪽 자식 또는 successor의 왼쪽 자식이 된다.
     *
     * 5 <- predecessor: lower_bound
     *  \
     *   7 <- successor: upper_bound
     *  /
     * 6
     * 또는
     *   7 <- successor
     *  /
     * 5 <- predecessor
     *  \
     *   6
     */
    int N;
    cin >> N;

    map<int, long long> m; // data, height
    map<int, long long>::iterator predecessor, successor;

    // exception handler: none of less/larger than x
    m.emplace(0, -1);
    m.emplace(N + 1, -1);

    long long height, count = 0;
    while(N--) {
        int n;
        cin >> n;

        // 최초에는 0, 300001이 들어가있어서 lower_bound는 존재하지 않음.
        // lower_bound의 결과값이 이상하게 도출돼 upper_bound를 쓰고 포인터를 하나 땡기는 식으로 사용
        successor = m.upper_bound(n);
        predecessor = successor;
        --predecessor;

        height = max(predecessor->second, successor->second) + 1;
        m.emplace(n, height);

        count += height;

        cout << count << "\n";
    }

    return 0;
}