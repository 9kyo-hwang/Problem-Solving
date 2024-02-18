#include <iostream>

// 못 품

using namespace std;

int N;
string dest;

enum
{
	ON = '0',
	OFF = '1'
};

void Flip(string &cur, const int i) // 원본 문자열 변경
{
	if(i > 0) cur[i - 1] = (cur[i - 1] == ON ? OFF : ON);
	cur[i] = (cur[i] == ON ? OFF : ON);
	if(i < N - 1) cur[i + 1] = (cur[i + 1] == ON ? OFF : ON);
}

int Operation(string cur, const bool state) // 문자열 복사본 필요
{
	int count = 0;

	if(state)
	{
		Flip(cur, 0);
		count++;
	}

	for(int i = 1; i < N; i++)
	{
		if(cur[i - 1] != dest[i - 1])
		{
			Flip(cur, i);
			count++;
		}
	}

	return cur != dest ? INT32_MAX : count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string cur;

	cin >> N;
	cin >> cur >> dest;
	const int num = min(Operation(cur, false), Operation(cur, true));
	cout << (num == INT32_MAX ? -1 : num);

	return 0;
}