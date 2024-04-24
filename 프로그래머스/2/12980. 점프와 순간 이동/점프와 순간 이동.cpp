using namespace std;
constexpr int MAX = 1000000000;

int solution(int n) {
    if(n == 0) {
        return 0;
    } else if(n < 0) {
        return MAX;
    } else {
        return n & 1 ? solution(n - 1) + 1 : solution(n / 2);
    }
}