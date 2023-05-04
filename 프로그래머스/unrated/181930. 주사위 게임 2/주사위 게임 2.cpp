#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    if(a != b && b != c && a != c)
        return a + b + c;
    if((a == b && b != c) || (b == c && a != b) || (a == c && a != b))
        return (a + b + c) * (a * a + b * b + c * c);
    if(a == b == c)
        return (a + b + c) * (a * a + b * b + c * c) * (a * a * a + b * b * b + c * c * c);
}