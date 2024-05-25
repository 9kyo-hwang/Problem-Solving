#include <cstdio>
#include <queue>

int main()
{
    int N, K; scanf(" %d %d", &N, &K);
    std::pair<int, int> Answer[2]{{0, -1}, {0,- 1}};  // {First(Satisfaction, Index), Second(S, I)}
    
    for(int n = 0; n < N; ++n)
    {
        std::priority_queue<std::pair<int, int>> PQ;
        for(int k = 0; k < K; ++k)
        {
            int a; scanf(" %d", &a);
            
            if(Answer[0].second != k)
            {
                PQ.emplace(Answer[0].first + a, k);
            }
            else
            {
                PQ.emplace(Answer[1].first + a, k);
            }
        }
        
        Answer[0] = PQ.top(); PQ.pop();
        Answer[1] = PQ.top(); PQ.pop();
    }
    
    printf("%d", Answer[0].first);

    return 0;
}