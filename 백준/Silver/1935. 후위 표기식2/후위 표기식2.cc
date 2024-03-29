#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iomanip>

using namespace std;

int main()
{
    int N; cin >> N;
    string PostfixNotation; cin >> PostfixNotation;
    
    unordered_map<char, int> AlphaPriorMap;
    for(int i = 0; i < N; ++i)
    {
        cin >> AlphaPriorMap[i + 'A'];
    }
    
    vector<double> Stack;
    for(const char& Operand : PostfixNotation)
    {
        if(AlphaPriorMap.count(Operand))
        {
            Stack.emplace_back(AlphaPriorMap[Operand]);
            continue;
        }
        
        double Num2 = Stack.back();
        Stack.pop_back();
        
        double Num1 = Stack.back();
        Stack.pop_back();
        
        switch(Operand)
        {
            case '+': Stack.emplace_back(Num1 + Num2); break;
            case '-': Stack.emplace_back(Num1 - Num2); break;
            case '*': Stack.emplace_back(Num1 * Num2); break;
            case '/': Stack.emplace_back(Num1 / Num2); break;
            default: break;
        }
    }
    
    cout << fixed << setprecision(2) << Stack.back();
    
    return 0;
}