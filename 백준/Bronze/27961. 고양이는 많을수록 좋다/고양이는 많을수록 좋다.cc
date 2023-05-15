#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    
    if(N == 0) {
        cout << 0;
        return 0;
    }
    
    cout << ceil(log2(N)) + 1;
    
    return 0;
}
