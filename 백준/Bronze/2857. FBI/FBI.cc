#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  bool flag = false;
  for (int i = 1; i <= 5; ++i) {
    string agent;
    cin >> agent;

    if (agent.find("FBI") != string::npos) {
      cout << i << " ";
      flag = true;
    }
  }

  if (!flag) cout << "HE GOT AWAY!";

  return 0;
}