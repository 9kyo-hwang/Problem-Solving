#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(string str1, string str2)
{
	for_each(str1.begin(), str1.end(), [](char& c) {c = tolower(c); });
	for_each(str2.begin(), str2.end(), [](char& c) {c = tolower(c); });

	vector<int> ms1(676, 0), ms2(676, 0);

	for (int i = 0; i < str1.length() - 1; i++)
	{
		if (!isalpha(str1[i]) || !isalpha(str1[i + 1])) continue;

		ms1[((str1[i] - 'a') * 26) + (str1[i + 1] - 'a')]++;
	}

	for (int i = 0; i < str2.length() - 1; i++)
	{
		if (!isalpha(str2[i]) || !isalpha(str2[i + 1])) continue;

		ms2[((str2[i] - 'a') * 26) + (str2[i + 1] - 'a')]++;
	}

	int num_union = 0, num_intersection = 0;
	for (int i = 0; i < 676; i++)
	{
		num_union += max(ms1[i], ms2[i]);
		num_intersection += min(ms1[i], ms2[i]);
	}

	return (num_union == 0 ? 65536 : (int)(((double) num_intersection / (double) num_union) * (double) 65536));
}