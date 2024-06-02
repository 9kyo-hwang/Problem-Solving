#include <string>
#include <vector>
#include <tuple>

using namespace std;

struct FCell
{
    int Up, Index, Down;
    FCell(int InUp, int InIndex, int InDown) 
        : Up(InUp), Index(InIndex), Down(InDown)
        {

        }
};

string solution(int n, int k, vector<string> InCommand) {
    vector<FCell> Table;
    for(int i = 0; i <= n; ++i)
    {
        Table.emplace_back(i - 1, i, i + 1);
    }
    vector<FCell> PoppedCell;
    string Answer(n, 'O');
    
    auto CommandU = [&](int X)
    {
        while(X--)
        {
            k = Table[k].Up;
        }
    };
    
    auto CommandD = [&](int X)
    {
        while(X--)
        {
            k = Table[k].Down;
        }
    };
    
    auto CommandC = [&]()
    {
        PoppedCell.emplace_back(Table[k]);
        const auto& [Up, Index, Down] = Table[k];
        
        if(0 <= Up)
        {
            Table[Up].Down = Down;
        }
        if(Down < n)
        {
            Table[Down].Up = Up;
        }
        
        Answer[k] = 'X';
        
        k = (Down == n ? Up : Down);
    };
    
    auto CommandZ = [&]()
    {
        const auto& [Up, Index, Down] = PoppedCell.back();
        PoppedCell.pop_back();
        
        if(0 <= Up)
        {
            Table[Up].Down = Index;
        }
        if(Down < n)
        {
            Table[Down].Up = Index;
        }
        
        Answer[Index] = 'O';
    };
    
    for(const string& Command : InCommand)
    {
        switch(Command[0])
        {
            case 'U':
                CommandU(stoi(Command.substr(2)));
                break;
            case 'D':
                CommandD(stoi(Command.substr(2)));
                break;
            case 'C':
                CommandC();
                break;
            case 'Z':
                CommandZ();
                break;
            default: 
                break;
        }
    }
    
    return Answer;
}