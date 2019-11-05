#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	long long n, m;
	long long mod[1000] = { 0, };
	long long i, j;
	long long sum = 0;

	scanf("%I64d %I64d", &n, &m);

	for (i = 1; i < m && i < n; i++)
	{
		mod[((i%m)*(i%m)) % m]++;
	}

	mod[0]++;

	for (i = 0; i < m; i++)
	{
		mod[i] *= n / m;
	}

	for (i = 1; i <= n % m; i++)
	{
		mod[((i%m)*(i%m)) % m]++;
	}

	for (i = 1; i < m / 2; i++)
	{
		sum += mod[i] * mod[m - i] * 2;
	}

	if (!(m % 2))
	{
		sum += mod[m / 2] * mod[m / 2];
	}

	printf("%I64d\n", sum + mod[0] * mod[0]);

	return 0;
}