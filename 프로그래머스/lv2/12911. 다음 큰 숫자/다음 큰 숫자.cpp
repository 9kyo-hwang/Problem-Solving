#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int nn = n + 1;
    while(bitset<8>(nn).count() != bitset<8>(n).count())
        nn++;
    return nn;
}