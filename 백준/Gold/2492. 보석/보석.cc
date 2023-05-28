#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, T, K; // width, height, num_stone, rect_size
  cin >> N >> M >> T >> K;

  vector<pair<int, int>> stones(T);
  for(auto &[x, y] : stones)
    cin >> x >> y;

  int max_count = 0;
  int max_x = 0, max_y = 0;
  for(int i = 0; i < T; i++) {
    int lt_x = min(stones[i].first, N - K);
    for(int j = 0; j < T; j++) {
      int lt_y = min(stones[j].second, M - K);

      int count = 0;
      for(const auto [x, y] : stones) {
        if((lt_x <= x && x <= lt_x + K) && (lt_y <= y && y <= lt_y + K))
          count++;
      }

      if(count > max_count) {
        max_count = count;
        max_x = lt_x;
        max_y = lt_y + K;
      }
    }
  }

  cout << max_x << " " << max_y << "\n" << max_count;

  return 0;
}