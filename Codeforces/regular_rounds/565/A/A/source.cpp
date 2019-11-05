#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 1000000007;

using namespace std;

int main()
{
	int n;
	int i;
	long long input;
	long long cnt = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		cnt = 0;
		scanf("%lld", &input);

		while (!(input % 2))
		{
			input /= 2;

			cnt++;
		}

		while (!(input % 3))
		{
			input /= 3;

			cnt+=2;
		}


		while (!(input % 5))
		{
			input /= 5;

			cnt+=3;
		}

		if (input != 1)
		{
			printf("-1\n");
		}

		else
		{
			printf("%lld\n", cnt);
		}
	}

	return 0;
}