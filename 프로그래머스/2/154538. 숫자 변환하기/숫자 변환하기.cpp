#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int solution(int x, int y, int n) {
    unordered_map<int, int> map;
    map[y] = 0;
    
    queue<int> q;
    q.emplace(y);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        if(front == x) {
            return map[front];
        }
        
        if(front <= 0) continue;
        
        if(front % 3 == 0 && map[front / 3] == 0) {
            map[front / 3] = map[front] + 1;
            q.emplace(front / 3);
        } 
        if(front % 2 == 0 && map[front / 2] == 0) {
            map[front / 2] = map[front] + 1;
            q.emplace(front / 2);
        }
        if(map[front - n] == 0) {
            map[front - n] = map[front] + 1;
            q.emplace(front - n);
        }
    }
    
    return -1;
}