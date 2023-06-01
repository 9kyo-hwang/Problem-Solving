#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  queue<int> q;
  int time = 0;
  int sum_weights = 0;

  for (const auto &w : truck_weights) {
    while (true) {
      if (q.size() >= bridge_length) { // pop first
        sum_weights -= q.front();
        q.pop();
      }
      if (sum_weights + w <= weight) { // push second
        q.emplace(w);
        sum_weights += w;
        time++;
        break;
      }
      q.emplace(0); // dummy. move truck
      time++;
    }
  }
    
    return time + bridge_length;
}