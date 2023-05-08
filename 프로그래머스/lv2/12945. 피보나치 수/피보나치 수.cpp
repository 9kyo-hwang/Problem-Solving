#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<long long> fib(100001, 0);
    fib[0] = 0, fib[1] = 1;
    for(int i = 2; i <= 100000; i++)
        fib[i] = (fib[i - 2] + fib[i - 1]) % 1234567;
    
    return fib[n];
}