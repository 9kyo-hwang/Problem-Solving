#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N; cin >> N;
	
	vector<int> stack;
	vector<char> operators;

	int num = 0;
	bool flag = true;
	while (N--) 
	{
		int n; cin >> n;
		while (num < n) 
		{
			num++;
			stack.emplace_back(num);
			operators.emplace_back('+');
		}

		if (stack.back() == n) 
		{
			stack.pop_back();
			operators.emplace_back('-');
		}
		else
		{
			flag = false;
			break;
		}
	}

	if (!flag) cout << "NO";
	else 
	{
		for (const char& ch : operators)
			cout << ch << "\n";
	}

	return 0;
}