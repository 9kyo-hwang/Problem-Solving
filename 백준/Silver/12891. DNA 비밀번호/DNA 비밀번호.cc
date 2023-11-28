#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int S, P;
  cin >> S >> P;

  string DNA;
  cin >> DNA;

  unordered_map<char, int> counts = {
      {'A', 0},
      {'C', 0},
      {'G', 0},
      {'T', 0},
  };

  deque<char> deq;
  for (int i = 0; i < P; i++) {
    deq.emplace_back(DNA[i]);
    counts[DNA[i]] += 1;
  }

  int satisfied_count[4]{};
  for (int i = 0; i < 4; i++) {
    cin >> satisfied_count[i];
  }
  
  auto is_satisfied = [&]() {
    return counts['A'] >= satisfied_count[0] &&
           counts['C'] >= satisfied_count[1] &&
           counts['G'] >= satisfied_count[2] &&
           counts['T'] >= satisfied_count[3];
  };

  int answer = is_satisfied();
  for (int i = P; i < S; i++) {
    char ch = deq.front();
    counts[ch] -= 1;
    deq.pop_front();

    ch = DNA[i];
    counts[ch] += 1;
    deq.emplace_back(ch);

    answer += is_satisfied();
  }

  cout << answer;

  return 0;
}