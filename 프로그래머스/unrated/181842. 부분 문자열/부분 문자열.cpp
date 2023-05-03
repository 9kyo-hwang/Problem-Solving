#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    auto pos = str2.find(str1);
    return 0 <= pos && pos < str2.length();
}