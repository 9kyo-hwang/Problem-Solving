#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, L;
  cin >> N >> M >> L;

  vector<int> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  v.emplace_back(0), v.emplace_back(L);

  sort(v.begin(), v.end());

  int low = 1, high = L - 1;
  int answer = 1001;
  while (low <= high) {
    int mid = (low + high) / 2;

    int numCanBuild = 0;
    for (int i = 1; i < v.size(); i++) {
      int dist = v[i] - v[i - 1];
      numCanBuild += dist / mid;  // 두 휴게소 간 지을 수 있는 휴게소 개수
      if (dist % mid == 0) numCanBuild--;  // 거리가 일치하는 경우, 끝 휴게소가 겹치므로 1개 감소
    }

    if (numCanBuild > M) {  // 짓고자 하는 휴게소 개수를 초과함.
      low = mid + 1;  // 길이가 너무 짧아서 발생한 문제이므로 길이 증가
    } else {  // 짓고자 하는 개수를 충족함
      answer = min(answer, mid);  // 그 중 거리가 제일 짧은 것을 취함
      high = mid - 1;
    }
  }

  cout << answer;

  return 0;
}