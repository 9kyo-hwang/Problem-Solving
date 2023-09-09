#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string numbers = "0"; // default
	const char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	for (int i = 1; i < t * m; i++)
	{
        int num = i;
		string str = "";
		while (num)
		{
			str += digits[num % n];
            num /= n;
		}
		reverse(str.begin(), str.end());
		numbers += str;
	}

	string answer = "";
	for (int i = (p - 1); i < t * m; i += m)
		answer += numbers[i];
	return answer;
}