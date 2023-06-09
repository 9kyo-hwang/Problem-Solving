#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> q;
    q.emplace(begin, 0);

    const int strlen = begin.length();

    while (!q.empty()) {
        const auto &[str, step] = q.front();
        q.pop();

        if (str == target)
            return step;

        for (int i = 0; i < words.size(); i++) {
            if (visited[i]) continue;
            
            int diff = 0;
            for (int j = 0; j < strlen; j++) {
                if (str[j] != words[i][j]) 
                    diff++;
            }

            if (diff != 1) continue;

            visited[i] = true;
            q.emplace(words[i], step + 1);
        }
    }
    
    return 0;
}