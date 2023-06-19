#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
  int begin = 0, end = 0;
  int min_len = sequence.size();
  int b = sequence.size(), e = sequence.size();
  int sum = sequence[end];

  while(end < sequence.size()) {
    if(sum < k) {
      sum += sequence[++end];
    } else if(sum > k) {
      sum -= sequence[begin++];
    } else {
      if(end - begin < min_len) {
        min_len = end - begin;
        b = begin;
        e = end;
      } else if(end - begin == min_len && begin < b) {
        b = begin;
        e = end;
      }

      sum -= sequence[begin++];
      sum += sequence[++end];
    }
  }
    
    return {b, e};
}