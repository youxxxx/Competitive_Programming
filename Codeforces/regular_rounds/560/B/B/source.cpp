#include<cstdio>
#include<vector>
#include<cmath>
#include<string>


using namespace std;

int main()
{
	int n;
	int cnt[200001] = { 0, };
	int cur = 1;
	int i;
	int ptr = 1;
	int lmax = 0;
	int input;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (input > lmax)
		{
			lmax = input;
		}

		cnt[input]++;
	}

	for (i = 1; i <= n; i++)
	{
		while (ptr < i)
		{
			ptr++;
		}

		if (ptr > lmax)
		{
			break;
		}

		while (cnt[ptr] == 0 && ptr <= lmax)
		{
			ptr++;
		}

		if (ptr > lmax)
		{
			break;
		}

		cnt[ptr]--;
	}

	printf("%d\n", i - 1);

	return 0;
}