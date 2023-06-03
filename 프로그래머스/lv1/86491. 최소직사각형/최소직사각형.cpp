#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
      int max_w = 0, max_h = 0;
  for(const auto& size : sizes) {
    int w = size[0], h = size[1];

    if(w < h)
      swap(w, h);

    max_w = max(max_w, w);
    max_h = max(max_h, h);
  }

    return max_w * max_h;
}