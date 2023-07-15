#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
  sort(routes.begin(), routes.end(), [](const vector<int> &p, const vector<int> &q) {
    return p[1] < q[1];
  }); // sort by exit position

  int cam_cnt = 0;
  int cam_pos = -30001;
  for (const auto &route : routes) {
    int entry_pos = route[0], exit_pos = route[1];
    if(entry_pos > cam_pos) { // entry position behind the camera
      cam_cnt += 1;
      cam_pos = exit_pos;
    }
  }

  return cam_cnt;
}