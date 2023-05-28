#include <cstdio>
#include <cstring>
#include <algorithm>

#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define swap(a, b, tmp) {tmp=a; a=b; b=tmp;}

int main()
{
    char str1[41], str2[41]; scanf("%s %s", str1, str2);
	int len1 = strlen(str1), len2 = strlen(str2);

	int dp[41][41] = {{0}};

	for(int i = 1; i <= len1; i++)
	{
		for(int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	char common[41]; int idx = 0;
	int r = len1, c = len2;
	while(dp[r][c])
	{
		if (dp[r][c] == dp[r - 1][c]) r--;
		else if (dp[r][c] == dp[r][c - 1]) c--;
		else
		{
			common[idx++] = str1[r - 1];
			r--; c--;
		}
	}
	common[idx] = '\0';

	int len3 = strlen(common);
	for(int i = 0; i < len3 / 2; i++)
    {
        char tmp;
        swap(common[i], common[len3 - i - 1], tmp);
    }

	printf("%s", common);
	return 0;
}