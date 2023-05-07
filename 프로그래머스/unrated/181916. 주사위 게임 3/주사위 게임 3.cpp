#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int a, int b, int c, int d) {
    vector<int> v(4);
    v[0] = a, v[1] = b, v[2] = c, v[3] = d;
    sort(v.begin(), v.end());
    
    a = v[0], b = v[1], c = v[2], d = v[3];
    
    // case 1
    if(a == b && b == c && c == d)
        return 1111 * a;
    
    // case 2
    if((a != b && b == c && c == d) ||
       a == b && b == c && c != d) {
        if(a != b)
            return pow(10 * b + a, 2);
        
        if(c != d)
            return pow(10 * c + d, 2);
    }
    
    // case 3
    if(a == b && b != c && c == d)
        return (b + c) * abs(b - c);
    
    // case 4
    if((a == b && b != c && c != d) ||
      (a != b && b == c && c != d) ||
      (a != b && b != c && c == d)) {
        if(a == b)
            return c * d;
        
        if(b == c)
            return a * d;
        
        if(c == d)
            return a * b;
    }
    
    // case 5
    if(a != b && b != c && c != d)
        return a;
}