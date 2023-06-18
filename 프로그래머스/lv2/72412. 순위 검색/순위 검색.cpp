#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
  unordered_map<string, int> map[4];
  map[0] = {{"cpp", 0}, {"java", 1}, {"python", 2}};
  map[1] = {{"backend", 0}, {"frontend", 1}};
  map[2] = {{"junior", 0}, {"senior", 1}};
  map[3] = {{"chicken", 0}, {"pizza", 1}};

  vector<int> table[3][2][2][2];

  for (const auto &str : info) {
    istringstream ss(str);
    string buffer;
    vector<string> buffers;
    while (getline(ss, buffer, ' '))
      buffers.emplace_back(buffer);
    table[map[0][buffers[0]]][map[1][buffers[1]]][map[2][buffers[2]]][map[3][buffers[3]]].emplace_back(stoi(buffers[4]));
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
      range[0] = {map[0][buffers[0]]};
    }

    if (buffers[2] == "-") {
      range[1] = {0, 1};
    } else {
      range[1] = {map[1][buffers[2]]};
    }

    if (buffers[4] == "-") {
      range[2] = {0, 1};
    } else {
      range[2] = {map[2][buffers[4]]};
    }

    if (buffers[6] == "-") {
      range[3] = {0, 1};
    } else {
      range[3] = {map[3][buffers[6]]};
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