#include<cstdio>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	int n;
	int i;
	char input[100001];
	int cnt[26] = { 0, };

	scanf("%d", &n);
	scanf("%s", input);

	if (n==1 || n > 26)
	{
		printf("YES");
	}

	else
	{
		for (i = 0; i < n; i++)
		{
			if (++cnt[input[i]-'a'] == 2)
			{
				printf("YES");

				break;
			}
		}

		if (i == n)
		{
			printf("NO");
		}
	}

	return 0;
}