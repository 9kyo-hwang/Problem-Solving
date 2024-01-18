#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i = 0; i < progresses.size(); i++) {
        int day = 0;
        while(progresses[i] < 100) {
            progresses[i] += speeds[i];
            day++;
        }
        for(int j = i + 1; j < speeds.size(); j++)
            progresses[j] += speeds[j] * day;
        
        int index = i;
        while(index < progresses.size() && progresses[index] >= 100)
            index++;
        answer.emplace_back(index - i);
        i = index - 1; // index는 size를 나타내게 되므로, i++까지 고려해 -2
    }
    
    return answer;
}