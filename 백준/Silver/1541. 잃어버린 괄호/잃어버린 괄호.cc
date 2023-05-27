#include <cstdio>

using namespace std;

int Num(int sum, int num, bool sub, char *str)
{
	if(*str == '+' || *str == '-' || *str == '\0')
	{
		sub ? sum -= num : sum += num;
		num = 0;
	}
	else num = num * 10 + *str - '0';

	if (*str == '-') sub = true;

	return *str == '\0' ? sum : Num(sum, num, sub, str + 1);
}

int main()
{
	char str[51]; scanf("%s", str);
	printf("%d", Num(0, 0, false, str));

	return 0;
}