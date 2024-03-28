#include <iostream>

using namespace std;
constexpr int MOD = 1e9 + 7;

int64_t Pow(int64_t Base, int64_t Exp)
{
    if(Exp == 1)
    {
        return Base;
    }
    
    int64_t NxtBase = Pow(Base, Exp / 2);
    if(Exp % 2 == 0)
    {
        return (NxtBase * NxtBase) % MOD;
    }
    else
    {
        return (NxtBase * NxtBase * Base) % MOD;
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        cout << (N <= 2 ? 1 : Pow(2, N - 2)) << "\n";
    }
    
    return 0;
}