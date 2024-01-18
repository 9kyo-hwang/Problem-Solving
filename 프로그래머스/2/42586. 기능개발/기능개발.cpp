#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    deque<int> progress_q(progresses.begin(), progresses.end()), speed_q(speeds.begin(), speeds.end());
    vector<int> answer;
    
    int day = 0, count = 0;
    while(!progress_q.empty()) {
        if(progress_q.front() + day * speed_q.front() >= 100) {
            progress_q.pop_front();
            speed_q.pop_front();
            count += 1;
        } else {
            if(count > 0) {
                answer.emplace_back(count);
                count = 0;
            }
            day += 1;
        }
    }
    answer.emplace_back(count);
    return answer;
}