#include <string>
#include <vector>
#include <queue>

using namespace std;

struct CmpByArrival {
  bool operator()(const vector<int> &a, const vector<int> &b) const {
    return a[0] > b[0] || a[0] == b[0] && a[1] > b[1];
  }
};

struct CmpByBurst {
  bool operator()(const vector<int> &a, const vector<int> &b) const {
    return a[1] > b[1];
  }
};

int solution(vector<vector<int>> jobs) {
  priority_queue<vector<int>, vector<vector<int>>, CmpByArrival> pq(jobs.begin(), jobs.end()); // process queue

  int total_return = pq.top()[1];
  vector<int> init = pq.top(); // 먼저 도착한 프로세스 중 작업 시간이 제일 짧은 거 우선 수행
  pq.pop();
  int current_time = init[0] + init[1]; // 첫 번째 프로세스 작업 후 시간을 현재 시간으로 설정

  priority_queue<vector<int>, vector<vector<int>>, CmpByBurst> wq; // waiting queue

  while (!pq.empty()) {
    while (!pq.empty() && pq.top()[0] <= current_time) { // 현재 시점 이전에 요청한(대기중인) 프로세스들
      wq.emplace(pq.top());
      pq.pop();
    }

    vector<int> current_process;
    if (wq.empty()) { // 대기 프로세스 없음
      current_process = pq.top(); // 프로세스 큐에서 가장 먼저 도착했고 그 중 작업 시간 짧은 프로세스 추출 후 수행
      pq.pop();

      total_return += current_process[1];
      current_time = current_process[0] + current_process[1]; // 시작 시간 + 작업 시간만큼 현재 시간 진행
    } else { // 대기 프로세스 존재
      current_process = wq.top(); // 대기 큐에서 작업 시간이 가장 짧은 프로세스 추출 후 수행
      wq.pop();

      total_return += current_time - current_process[0]; // 요청 시간에서 딜레이된 정도
      total_return += current_process[1]; // 작업 시간
      current_time += current_process[1]; // 작업 시간만큼 현재 시간 진행

      while (!wq.empty()) { // 남은 대기 프로세스 모두 프로세스 큐로 이동
        pq.emplace(wq.top());
        wq.pop();
      }
    }

    wq = priority_queue<vector<int>, vector<vector<int>>, CmpByBurst>(); // waiting queue clear
  }

  return total_return / jobs.size();
}