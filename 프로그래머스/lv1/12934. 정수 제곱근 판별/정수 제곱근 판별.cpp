#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    auto nn = sqrt(n);
    if((nn - (int)nn) != 0)
        return -1;
    
    return pow(nn + 1, 2);
}