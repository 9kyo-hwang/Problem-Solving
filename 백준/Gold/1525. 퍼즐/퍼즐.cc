#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string BeginBoard = "";
  char Ch;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> Ch;
      BeginBoard += Ch;
    }
  }

  const int Offset[][2] = {
      {-1, 0},
      {0, 1},
      {1, 0},
      {0, -1},
  };

  queue<pair<string, int>> Q;
  unordered_set<string> Visited;

  Q.emplace(BeginBoard, 0);
  Visited.emplace(BeginBoard);

  const string &EndBoard = "123456780";

  int answer = -1;
  while (!Q.empty()) {
    const auto [CurrentBoard, CurrentStep] = Q.front();
    Q.pop();

    if (CurrentBoard == EndBoard) {
      answer = CurrentStep;
      break;
    }

    int EmptyPos = CurrentBoard.find('0');
    int EmptyX = EmptyPos / 3, EmptyY = EmptyPos % 3;

    for (const auto &Dir : Offset) {
      int NextX = EmptyX + Dir[0], NextY = EmptyY + Dir[1];
      if (NextX < 0 || NextX >= 3 || NextY < 0 || NextY >= 3) {
        continue;
      }

      string NextBoard = CurrentBoard;
      swap(NextBoard[EmptyX * 3 + EmptyY], NextBoard[NextX * 3 + NextY]);

      if (Visited.find(NextBoard) != Visited.end()) {
        continue;
      }

      Q.emplace(NextBoard, CurrentStep + 1);
      Visited.emplace(NextBoard);
    }
  }

  cout << answer;

  return 0;
}