#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string MBTI[16] = {
      "ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP",
      "ESTJ", "ESFJ", "ENFJ", "ENTJ", "ESTP", "ESFP", "ENFP", "ENTP",
  };

  int dist[16][16] = {{0,}};
  for(int i = 0; i < 16; i++) {
    for(int j = 0; j < 16; j++) {
      int d = 0;
      for(int k = 0; k < 4; k++) {
        if(MBTI[i][k] != MBTI[j][k])
          d++;
      }
      dist[i][j] = d;
    }
  }

  unordered_map<string, int> map;
  for(int i = 0; i < 16; i++)
    map[MBTI[i]] = i;

  int T;
  cin >> T;

  for(int t = 0; t < T; t++) {
    int N;
    cin >> N;

    vector<int> mbti(N);
    string str;
    for(int n = 0; n < N; n++) {
      cin >> str;
      mbti[n] = map[str];
    }

    int minimum = 12;
    if(N > 32) {
      minimum = 0;
    } else {
      for(int i = 0; i < N - 2; i++) {
        for(int j = i + 1; j < N - 1; j++) {
          for(int k = j + 1; k < N; k++) {
            minimum = min(minimum, dist[mbti[i]][mbti[j]] + dist[mbti[i]][mbti[k]] + dist[mbti[j]][mbti[k]]);
          }
        }
      }
    }

    cout << minimum << "\n";
  }

  return 0;
}