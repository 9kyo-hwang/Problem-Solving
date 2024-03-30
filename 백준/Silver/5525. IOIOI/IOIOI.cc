#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int N, M; string S;
  cin >> N >> M >> S;

  int count = 0;
  for(auto i = 0; i < M; i++) {
	if(S[i] != 'I') continue;

	int len = 0;
	while(S[i + 1] == 'O' && S[i + 2] == 'I') {
	  len++;

	  if(len == N) {
		len--; // 다시 1을 감소시켜야 끝 'OI' overlap
		count++;
	  }

	  i += 2;
	}
  }

  cout << count;

  return 0;
}