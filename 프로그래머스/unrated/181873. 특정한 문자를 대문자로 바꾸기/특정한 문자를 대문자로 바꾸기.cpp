#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    for(auto &ch : my_string) {
        if(ch == alp[0])
            ch -= 32; // ascii 코드 상에서 소문자와 대문자의 차이가 32. 32를 더하면 대문자, 32를 빼면 소문자
    }
    return my_string;
}