#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

bool IsAlphabet(char ch) {
  return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

int solution(string str1, string str2) {
  transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
  transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

  vector<string> v1, v2;
  unordered_map<string, int> m1, m2;

  for (int i = 0; i < str1.length() - 1; i += 1) {
    if (!IsAlphabet(str1[i]) || !IsAlphabet(str1[i + 1]))
      continue;

    auto str = string(&str1[i], &str1[i + 2]);
    if (m1[str] == 0)
      v1.emplace_back(str);
    m1[str] += 1;
  }
  sort(v1.begin(), v1.end());

  for (int i = 0; i < str2.length() - 1; i += 1) {
    if (!IsAlphabet(str2[i]) || !IsAlphabet(str2[i + 1]))
      continue;

    auto str = string(&str2[i], &str2[i + 2]);
    if (m2[str] == 0)
      v2.emplace_back(str);
    m2[str] += 1;
  }
  sort(v2.begin(), v2.end());

  multiset<string> unions, intersections;
  int i = 0, j = 0;

  while(i < v1.size() && j < v2.size()) {
    int cmp = v1[i].compare(v2[j]);

    if(cmp < 0) {
      for(int k = 0; k < m1[v1[i]]; k += 1)
        intersections.emplace(v1[i]);
      i += 1;
    } else if(cmp > 0) {
      for(int k = 0; k < m2[v2[j]]; k += 1)
        intersections.emplace(v2[j]);
      j += 1;
    } else {
      int min_freq = min(m1[v1[i]], m2[v2[j]]);
      int max_freq = max(m1[v1[i]], m2[v2[j]]);

      for(int k = 0; k < min_freq; k += 1)
        unions.emplace(v1[i]);

      for(int k = 0; k < max_freq; k += 1)
        intersections.emplace(v2[j]);

      i += 1;
      j += 1;
    }
  }

  while(i < v1.size()) {
    for(int k = 0; k < m1[v1[i]]; k += 1)
      intersections.emplace(v1[i]);
    i += 1;
  }

  while(j < v2.size()) {
    for(int k = 0; k < m2[v2[j]]; k += 1)
      intersections.emplace(v2[j]);
    j += 1;
  }

  if(intersections.empty())
    return 65536;

  double similarity = unions.size() / (double)intersections.size();
  return similarity * 65536;
}