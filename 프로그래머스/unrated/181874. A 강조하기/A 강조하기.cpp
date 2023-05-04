#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for(auto &ch : myString) {
        if(ch == 'a')
            ch -= 32;
        else if('B' <= ch && ch <= 'Z')
            ch += 32;
    }
    return myString;
}