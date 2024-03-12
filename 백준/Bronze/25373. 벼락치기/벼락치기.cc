#include <iostream>

using namespace std;
using int64 = long long;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int64 N; cin >> N;
    if(N > 21)
    {
        int64 Tmp = N;
        while(true)
        {
            if(Tmp % 7 == 0)
            {
                cout << Tmp / 7 + 3;
                break;
            }
            Tmp += 1;
        }
    }
    else
    {
        if(N <= 1) cout << 1;
        else if(N <= 3) cout << 2;
        else if(N <= 6) cout << 3;
        else if(N <= 10) cout << 4;
        else if(N <= 15) cout << 5;
        else if(N <= 21) cout << 6;
    }

    return 0;
}