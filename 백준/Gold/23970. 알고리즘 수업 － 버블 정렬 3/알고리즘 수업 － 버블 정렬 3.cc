#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N; cin >> N;
    
    vector<int> A(N), B(N);
    for(int& i : A)
    {
        cin >> i;
    }
    for(int& i : B)
    {
        cin >> i;
    }
    
    auto BubbleSort = [&]()
    {
        if(A == B)
        {
            return true;
        }
        
        for(int i = N - 1; i > 0; --i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(A[j] <= A[j + 1])
                {
                    continue;
                }
                
                swap(A[j], A[j + 1]);
                if(A[j] == B[j] && A == B)
                {
                    return true;
                }
            }
        }
        
        return false;
    };
    
    cout << BubbleSort();
    
    return 0;
}