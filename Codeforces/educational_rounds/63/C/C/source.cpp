#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;

	while (b != 0)
	{
		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	int n, m;
	vector<long long> ev, interv;
	int i;
	long long input;
	long long dis;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		ev.push_back(input);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%I64d", &input);

		interv.push_back(input);
	}

	dis = ev[1] - ev[0];

	for (i = 2; i < n; i++)
	{
		dis = gcd(ev[i] - ev[i - 1], dis);
	}

	for (i = 0; i < m; i++)
	{
		if (!(dis%interv[i]))
		{
			printf("YES\n%I64d %d\n", ev[0], i + 1);

			return 0;
		}
	}

	printf("NO\n");

	return 0;
}