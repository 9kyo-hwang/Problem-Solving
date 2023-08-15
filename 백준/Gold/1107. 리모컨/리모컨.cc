#include <iostream>

using namespace std;

int N, M;
bool is_broken[10] = { false, };

int input_count(int i) {
  int tmp = i, input = 0;

  do {
	if(is_broken[tmp % 10])
	  return -1;
	
	tmp /= 10;
	input++;
  } while(tmp > 0);

  return input;
}

int find_num() {
  if(M >= 10) // 모든 버튼 고장, 숫자 만들기 불가능
	return abs(N - 100);

  int min = abs(N - 100);
  for(int i = 0; i <= 1000000; i++) {
	int num_input = input_count(i);
	if(num_input == -1)
	  continue;

	int sum_input = num_input + abs(N - i);

	if(sum_input < min)
	  min = sum_input;
  }

  return min;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  cin >> N >> M;
  while(M--) {
	int m;
	cin >> m;
	is_broken[m] = true;
  }

  if(M == 0) {
	int digit = 0;
	int tmp = N;
	while(tmp) {
	  digit++;
	  tmp /= 10;
	}
	cout << min(abs(N - 100), digit);
  } else {
	cout << find_num();
  }

  return 0;
}