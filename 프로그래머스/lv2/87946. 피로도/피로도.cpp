#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const vector<int>& p, const vector<int>& q) {
  return p[0] > q[0] || p[0] == q[0] && p[1] < q[1];
}

int solution(int k, vector<vector<int>> dungeons) {
  sort(dungeons.begin(), dungeons.end(), Compare);
  int answer = -1;
  do {
    int count = 0;
    int fatigue = k;

    for (const auto &dungeon : dungeons) {
      int necessary = dungeon[0];
      int consumption = dungeon[1];

      if (fatigue >= necessary) {
        fatigue -= consumption;
        count++;
      }
    }
    answer = max(answer, count);
  } while (next_permutation(dungeons.begin(), dungeons.end(), Compare));
    return answer;
}