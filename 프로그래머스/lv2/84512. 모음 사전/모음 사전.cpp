#include <string>
#include <vector>

using namespace std;

vector<string> vowel = {"A", "E", "I", "O", "U"};

bool DFS(const string& target, const string& str, int &count) {
  if(str.length() > 5)
    return false;

  if(target == str)
    return true;
  
  count++;
  for(const auto& ch : vowel) {
    if(DFS(target, str + ch, count))
      return true;
  }

  return false;
}

int solution(string word) {
    int answer = 0;
    DFS(word, {}, answer);
    return answer;
}