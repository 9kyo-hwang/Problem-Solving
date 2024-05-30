#include <iostream>
#include <set>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    set<int> ProblemByLevel[101];
    set<int> ProblemByLevelAndGroup[101][101];
    pair<int, int> Problems[100001];
    
    int N; cin >> N;
    while(N--)
    {
        int P, L, G; cin >> P >> L >> G;
        
        ProblemByLevel[L].emplace(P);
        ProblemByLevelAndGroup[L][G].emplace(P);
        Problems[P] = {L, G};
    }
    
    int M; cin >> M;
    while(M--)
    {
        string Command; cin >> Command;
        if(Command == "recommend")  // find Max/Min in Category G
        {
            int G, x; cin >> G >> x;
            if(x == 1)
            {
                for(int L = 100; L >= 1; --L)
                {
                    if(!ProblemByLevelAndGroup[L][G].empty())
                    {
                        cout << *(--ProblemByLevelAndGroup[L][G].end()) << "\n";
                        break;
                    }
                }
            }
            else if(x == -1)
            {
                for(int L = 1; L <= 100; ++L)
                {
                    if(!ProblemByLevelAndGroup[L][G].empty())
                    {
                        cout << *ProblemByLevelAndGroup[L][G].begin() << "\n";
                        break;
                    }
                }
            }
        }
        else if(Command == "recommend2")  // find Max/Min any Category
        {
            int x; cin >> x;
            if(x == 1)
            {
                for(int L = 100; L >= 1; --L)
                {
                    if(!ProblemByLevel[L].empty())
                    {
                        cout << *(--ProblemByLevel[L].end()) << "\n";
                        break;
                    }
                }
            }
            else if(x == -1)
            {
                for(int L = 1; L <= 100; ++L)
                {
                    if(!ProblemByLevel[L].empty())
                    {
                        cout << *ProblemByLevel[L].begin() << "\n";
                        break;
                    }
                }
            }
        }
        else if(Command == "recommend3")  // find lower bound
        {
            int x, L; cin >> x >> L;
            bool Flag = false;
            if(x == 1)
            {
                for(; L <= 100; ++L)
                {
                    if(!ProblemByLevel[L].empty())
                    {
                        cout << *ProblemByLevel[L].begin() << "\n";
                        Flag = true;
                        break;
                    }
                }
            }
            else if(x == -1)
            {
                for(L -= 1; L >= 1; --L)
                {
                    if(!ProblemByLevel[L].empty())
                    {
                        cout << *(--ProblemByLevel[L].end()) << "\n";
                        Flag = true;
                        break;
                    }
                }
            }
            
            if(!Flag)
            {
                cout << "-1\n";
            }
        }
        else if(Command == "add")
        {
            int P, L, G; cin >> P >> L >> G;
            
            ProblemByLevel[L].emplace(P);
            ProblemByLevelAndGroup[L][G].emplace(P);
            Problems[P] = {L, G};
        }
        else if(Command == "solved")
        {
            int P; cin >> P;
            ProblemByLevel[Problems[P].first].erase(P);
            ProblemByLevelAndGroup[Problems[P].first][Problems[P].second].erase(P);
        }
    }
    
    return 0;
}