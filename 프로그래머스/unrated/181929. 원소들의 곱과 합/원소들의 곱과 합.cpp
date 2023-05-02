#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int product = 1;
    int square = 0;
    for(const auto i : num_list) {
        product *= i;
        square += i;
    }
    square *= square;
    return product < square ? 1 : 0;
}