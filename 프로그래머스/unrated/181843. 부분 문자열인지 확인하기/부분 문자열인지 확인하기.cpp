#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) {
    return 0 <= my_string.find(target) && my_string.find(target) < my_string.length();
}