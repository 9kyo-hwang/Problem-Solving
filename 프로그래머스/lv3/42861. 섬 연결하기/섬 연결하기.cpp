#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class UnionFind {
  public:
    UnionFind(int size) {
        p_ = vector<int>(size);
        for(int i = 0; i < size; i++)
            p_[i] = i;
        size_ = vector<int>(size, 1);
    }
    ~UnionFind() = default;
    
    bool IsCycle(const int x, const int y) { return Find(x) == Find(y); }
    
    void Union(const int u, const int v) {
        int x = Find(u);
        int y = Find(v);
        
        if(size_[x] > size_[y]) {
            p_[y] = x;
            size_[x] += size_[y];
        } else {
            p_[x] = y;
            size_[y] += size_[x];
        }
    }
    
  private:
    vector<int> p_, size_;
    int Find(int x) {
        while(x != p_[x]) {
            p_[x] = p_[p_[x]];
            x = p_[x];
        }
        
        return p_[x];
    }
};

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    UnionFind uf(n);
    int answer = 0;
    for(const auto& edge: costs) {
        const int x = edge[0];
        const int y = edge[1];
        const int cost = edge[2];
        
        if(!uf.IsCycle(x, y)) {
            uf.Union(x, y);
            answer += cost;
        }
    }
    return answer;
}