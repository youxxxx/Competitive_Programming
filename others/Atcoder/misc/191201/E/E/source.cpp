#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

#define MOD 1000000007

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	int cnt[3] = { 0, };

	long long sol = 1;

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		long long mult = 0;
		int ptr = -1;

		for (int j = 0; j < 3; j++)
		{
			if (cnt[j] == input)
			{
				mult++;

				ptr = j;
			}
		}

		if (ptr == -1)
		{
			printf("0\n");

			return 0;
		}

		sol = sol*mult%MOD;

		cnt[ptr]++;
	}

	printf("%lld\n", sol);

	return 0;
}