#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
  bool operator()(const vector<int> &p, const vector<int> &q) const {
    return p[1] > q[1];
  }
};

int solution(vector<vector<int>> jobs) {
  sort(jobs.begin(), jobs.end(), [](const vector<int> &p, const vector<int> &q) {
    return p[0] < q[0] || p[0] == q[0] && p[1] < q[1];
  }); // 요청 순 -> 짧은 작업 시간 순

  int current_time = 0;
  int index = 0;
  int finish = 0;

  priority_queue<vector<int>, vector<vector<int>>, compare> pq;

  int total_time = 0;
  while(finish < jobs.size()) {
    while(index < jobs.size() && jobs[index][0] <= current_time) {
      pq.emplace(jobs[index]); // 현재 시각 이전에 요청한 작업들 큐에 삽입
      index += 1;
    }

    if(pq.empty()) { // 큐가 비었다면(이전에 요청한 작업이 없다면)
      current_time = jobs[index][0]; // 다음 작업 시작 시간대로 이동
      continue;
    }

    vector<int> process = pq.top(); // 이전에 요청한 작업들 중 처리 시간이 가장 짧은 작업 수행
    pq.pop();

    total_time += (current_time - process[0]) + process[1]; // (현재 시각 - 최초 요청 시각) + 수행 시간
    current_time += process[1]; // 현재 시각을 작업 완료 후 시각으로 이동
    finish += 1; // 완료된 작업 개수 증가
  }

  return total_time / jobs.size();
}