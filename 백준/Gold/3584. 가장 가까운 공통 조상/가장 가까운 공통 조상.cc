#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        vector<int> Parents(N + 1, 0);
        iota(Parents.begin(), Parents.end(), 0);
        
        for(int i = 0; i < N - 1; ++i)
        {
            int A, B; cin >> A >> B;
            Parents[B] = A;
        }
        
        vector<bool> Visited(N + 1, false);
        Visited[0] = true;
        
        int X, Y; cin >> X >> Y;
        
        do
        {
            Visited[X] = true;
            X = Parents[X];
        } while(!Visited[X]);
        
        do
        {
            Visited[Y] = true;
            Y = Parents[Y];
        } while(!Visited[Y]);
        
        cout << Y << "\n";
    }
    
    return 0;
}