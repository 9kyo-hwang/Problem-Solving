#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p = 0, y = 0;
    for(const auto& c : s) {
        if(c == 'p' || c == 'P')
            p++;
        else if(c == 'y' || c == 'Y')
            y++;
    }

    return p == y;
}