#include <cstdio>
#include <queue>

#define Satisfaction first
#define Index second

int main()
{
    int N, K; scanf(" %d %d", &N, &K);
    std::pair<int, int> Answer[2]{{0, -1}, {0,- 1}};
    
    for(int n = 0; n < N; ++n)
    {
        std::priority_queue<std::pair<int, int>> PQ;
        for(int k = 0; k < K; ++k)
        {
            int a; scanf(" %d", &a);
            
            if(Answer[0].Index != k)
            {
                PQ.emplace(Answer[0].Satisfaction + a, k);
            }
            else
            {
                PQ.emplace(Answer[1].Satisfaction + a, k);
            }
        }
        
        Answer[0] = PQ.top(); PQ.pop();
        Answer[1] = PQ.top(); PQ.pop();
    }
    
    printf("%d", Answer[0].Satisfaction);

    return 0;
}