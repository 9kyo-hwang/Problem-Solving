#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
  string str;
  cin >> str;

  list<char> strlist(str.begin(), str.end());
  auto cursor = strlist.end();

  int M;
  cin >> M;

  while (M--) {
    char cmd;
    cin >> cmd;

    switch (cmd) {
      case 'L': {
        if (cursor != strlist.begin()) {
          --cursor;
        }
        break;
      }
      case 'D': {
        if (cursor != strlist.end()) {
          ++cursor;
        }
        break;
      }
      case 'B': {
        if (cursor != strlist.begin()) {
          cursor = strlist.erase(--cursor);
        }
        break;
      }
      case 'P': {
        char ch;
        cin >> ch;

        strlist.insert(cursor, ch);  // 기존 커서 위치를 유지하기 위해 반환값(ch의 위치)을 사용하지 않음
        break;
      }
      default:
        break;
    }
  }

  for (const auto &ch : strlist) {
    cout << ch;
  }
  return 0;
}