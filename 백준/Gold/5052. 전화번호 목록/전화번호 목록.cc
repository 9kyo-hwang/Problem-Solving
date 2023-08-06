#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto CheckFtn = [&](const vector<vector<string>> &v) {
    for (const auto &numbers : v) {
      auto size = numbers.size();
      if(size == 0)
        continue;

      for (int i = 0; i < size - 1; i++) {
        auto str = numbers[i].c_str();
        auto len = numbers[i].length();
        for (int j = i + 1; j < size; j++) {
          if (strncmp(str, numbers[j].c_str(), len) == 0) {
            return false;
          }
        }
      }
    }

    return true;
  };

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<vector<string>> phone_numbers(10);

    while (n--) {
      string phone_number;
      cin >> phone_number;

      switch (phone_number[0] - '0') {
        case 0: phone_numbers[0].emplace_back(phone_number);
          break;
        case 1: phone_numbers[1].emplace_back(phone_number);
          break;
        case 2: phone_numbers[2].emplace_back(phone_number);
          break;
        case 3: phone_numbers[3].emplace_back(phone_number);
          break;
        case 4: phone_numbers[4].emplace_back(phone_number);
          break;
        case 5: phone_numbers[5].emplace_back(phone_number);
          break;
        case 6: phone_numbers[6].emplace_back(phone_number);
          break;
        case 7: phone_numbers[7].emplace_back(phone_number);
          break;
        case 8: phone_numbers[8].emplace_back(phone_number);
          break;
        case 9: phone_numbers[9].emplace_back(phone_number);
          break;
        default: break;
      }
    }

    for (auto &numbers : phone_numbers) {
      sort(numbers.begin(), numbers.end(), [](const string &a, const string &b) {
        return a.length() < b.length();
      });
    }

    cout << (CheckFtn(phone_numbers) ? "YES" : "NO") << "\n";
  }

  return 0;
}