#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, K; cin >> N >> K;
    
    auto OutOfBound = [&](int X)
    {
        return X < 0 || X > 100000;
    };
    
    deque<pair<int, int>> Q;
    vector<bool> Visited(100001, false);
    
    Q.emplace_back(N, 0);
    Visited[N] = true;
    
    int AnswerTick = 100001, AnswerSize = 0;
    while(!Q.empty())
    {
        const auto [X, T] = Q.front();
        Q.pop_front();
        
        if(X == K)
        {
            if(T < AnswerTick)
            {
                AnswerTick = T;
                AnswerSize = 1;
            }
            else if(T == AnswerTick)
            {
                AnswerSize += 1;
            }
        }
        
        Visited[X] = true;
        for(const int Nx : {X - 1, X + 1, X * 2})
        {
            if(OutOfBound(Nx) || Visited[Nx])
            {
                continue;
            }
            
            Q.emplace_back(Nx, T + 1);
        }
    }
    
    cout << AnswerTick << "\n" << AnswerSize;
    
    return 0;
}