#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N; cin >> N;
    
    vector<int> A(N, 0);
    for(int& Num : A)
    {
        cin >> Num;
    }
    
    vector<int> Cresendo(N, 1), Decresendo(N, 1);
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(A[j] < A[i] && Cresendo[j] + 1 > Cresendo[i])
            {
                Cresendo[i] = Cresendo[j] + 1;
            }
        }
    }
    
    for(int i = N - 1; i >= 0; --i)
    {
        for(int j = N - 1; j > i; --j)
        {
            if(A[i] > A[j] && Decresendo[j] + 1 > Decresendo[i])
            {
                Decresendo[i] = Decresendo[j] + 1;
            }
        }
    }
    
    int Answer = 0;
    for(int i = 0; i < N; ++i)
    {
        Answer = max(Answer, Cresendo[i] + Decresendo[i] - 1);
    }
    cout << Answer;
    
    return 0;
}