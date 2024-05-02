#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string N; cin >> N;
    if(N.size() == 1)
    {
        N = '0' + N;
    }
    
    string Num = N;
    int Cnt = 1;
    while(true)
    {
        string Sum{to_string((Num[0] - '0') + (Num[1] - '0'))};
        string Tmp{Num.back(), Sum.back()};

        if(N == Tmp)
        {
            cout << Cnt;
            break;
        }
        
        Num = Tmp;
        Cnt += 1;
    }

    return 0;
}