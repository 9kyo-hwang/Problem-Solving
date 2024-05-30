#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    using FProblem = pair<int, int>;  // L, P

    map<int, multiset<FProblem>> Groups;  // G : {L, P}, ...
    multiset<FProblem> Levels;              // {L, P}, ...
    map<int, FProblem> Problems;                // P : {L, G}
    
    int N; cin >> N;
    while(N--)
    {
        int P, L, G; cin >> P >> L >> G;
        Groups[G].emplace(L, P);
        Levels.emplace(L, P);
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
                cout << (--Groups[G].end())->second << "\n";
            }
            else if(x == -1)
            {
                cout << Groups[G].begin()->second << "\n";
            }
        }
        else if(Command == "recommend2")  // find Max/Min any Category
        {
            int x; cin >> x;
            if(x == 1)
            {
                cout << (--Levels.end())->second << "\n";
            }
            else if(x == -1)
            {
                cout << Levels.begin()->second << "\n";
            }
        }
        else if(Command == "recommend3")  // find lower bound
        {
            int x, L; cin >> x >> L;
            if(x == 1)
            {
                auto it = Levels.lower_bound({L, 0});
                if(it != Levels.end())
                {
                    cout << it->second << "\n";
                }
                else
                {
                    cout << "-1\n";
                }
            }
            else if(x == -1)
            {
                auto it = Levels.upper_bound({L, 0});
                if(it != Levels.begin())
                {
                    cout << (--it)->second << "\n";
                }
                else
                {
                    cout << "-1\n";
                }
            }
        }
        else if(Command == "add")
        {
            int P, L, G; cin >> P >> L >> G;
            
            Groups[G].emplace(L, P);
            Levels.emplace(L, P);
            Problems[P] = {L, G};
        }
        else if(Command == "solved")
        {
            int P; cin >> P;
            const auto& [L, G] = Problems[P];
            
            Groups[G].erase({L, P});
            Levels.erase({L, P});
            Problems.erase(P);
        }
    }
    
    return 0;
}