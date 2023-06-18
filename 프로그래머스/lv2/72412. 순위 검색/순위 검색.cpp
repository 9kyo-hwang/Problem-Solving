#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
  unordered_map<string, int> languages;
  languages["cpp"] = 0;
  languages["java"] = 1;
  languages["python"] = 2;

  unordered_map<string, int> groups;
  groups["backend"] = 0;
  groups["frontend"] = 1;

  unordered_map<string, int> careers;
  careers["junior"] = 0;
  careers["senior"] = 1;

  unordered_map<string, int> foods;
  foods["chicken"] = 0;
  foods["pizza"] = 1;

  vector<int> table[3][2][2][2];

  for (const auto &str : info) {
    istringstream ss(str);
    string buffer;
    vector<string> buffers;
    while (getline(ss, buffer, ' '))
      buffers.emplace_back(buffer);
    table[languages[buffers[0]]][groups[buffers[1]]][careers[buffers[2]]][foods[buffers[3]]].emplace_back(stoi(buffers[4]));
  }

  vector<int> result;
  for (const auto &q : query) {
    istringstream ss(q);
    string buffer;
    vector<string> buffers;
    while (getline(ss, buffer, ' '))
      buffers.emplace_back(buffer);

    int score = stoi(buffers[7]);
    int count = 0;

    vector<int> range[4];
    if (buffers[0] == "-") {
      range[0] = {0, 1, 2};
    } else {
      range[0] = {languages[buffers[0]]};
    }

    if (buffers[2] == "-") {
      range[1] = {0, 1};
    } else {
      range[1] = {groups[buffers[2]]};
    }

    if (buffers[4] == "-") {
      range[2] = {0, 1};
    } else {
      range[2] = {careers[buffers[4]]};
    }

    if (buffers[6] == "-") {
      range[3] = {0, 1};
    } else {
      range[3] = {foods[buffers[6]]};
    }

    for (const auto &i : range[0]) {
      for (const auto &j : range[1]) {
        for (const auto &k : range[2]) {
          for (const auto &l : range[3]) {
            for (const auto &s : table[i][j][k][l]) {
              if (s >= score)
                count += 1;
            }
          }
        }
      }
    }

    result.emplace_back(count);
  }
    
    return result;
}