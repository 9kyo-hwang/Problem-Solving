#include <iostream>
#include <vector>

using namespace std;

using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<ull> times(N);
  for(ull &i : times) {
    cin >> i;
  }
    
  // 가장 빨리 끝나는 경우: 1분 걸리는 심사관한테 1명
  // 가장 늦게 끝나는 경우: 가장 오래 걸리는 심사관한테 M명
  ull min_time = 1, max_time = times.back() * M;
  
  while(min_time <= max_time) {
    ull avg_time = (min_time + max_time) / 2;
    ull pass = 0;

    // 지금 평균 처리 시간으로 몇 명을 심사할 수 있는가?
    for(const ull &t : times) {
      pass += avg_time / t;
    }

    if(pass >= M) { // 모두 처리할 수 있다면 최대 시간 감소
      max_time = avg_time - 1;
    } else { // 불가능 하다면 최소 시간 증가
      min_time = avg_time + 1;
    }
  }

  cout << max_time + 1;

  return 0;
}