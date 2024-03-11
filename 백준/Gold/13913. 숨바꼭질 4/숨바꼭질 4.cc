#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, K; cin >> N >> K;
    vector<int> Distances(100001, -1);
    vector<int> Parents(100001, 0);
    iota(Parents.begin(), Parents.end(), 0);
    
    deque<int> Q;
    Q.emplace_back(N);
    Distances[N] = 0;
    
    while(!Q.empty())
    {
        const int X = Q.front();
        Q.pop_front();
        
        if(X == K)
        {
            cout << Distances[X] << "\n";
            break;
        }
        
        for(const int D : {X, -1, 1})
        {
            int NX = X + D;
            if(NX < 0 || NX > 100000 || Distances[NX] != -1 && Distances[NX] < Distances[X] + 1)
            {
                continue;
            }

            Distances[NX] = Distances[X] + 1;
            Parents[NX] = X;
            Q.emplace_back(NX);
        }
    }
    
    deque<int> Paths;
    
    int Pos = K;
    while(Pos != N)
    {
        Paths.emplace_front(Pos);
        Pos = Parents[Pos];
    }
    Paths.emplace_front(Pos);
    
    for(const int P : Paths)
    {
        cout << P << " ";
    }

    return 0;
}