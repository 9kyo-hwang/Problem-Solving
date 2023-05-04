#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for(auto &ch : myString) {
        if(ch < 'l')
            ch = 'l';
    }
    return myString;
}