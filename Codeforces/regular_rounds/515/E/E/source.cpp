#include<cstdio>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	int n, m;
	char input[200001];
	int times[200001];
	string a, b;
	int i;
	int acc = 0;
	int left = 0;
	long long res = 0, base = 1, p;

	scanf("%d %d", &n, &m);

	scanf("%s", input);

	a = input;

	scanf("%s", input);

	b = input;

	for (i = 0; i < m; i++)
	{
		if (b[i] - '0')
		{
			acc++;
		}

		times[i] = acc;
	}

	for (i = n - 1; i >= 0 && m - n + i >= 0; i--)
	{
		if (a[i] - '0')
		{
			res = (res + base*times[m - n + i]) % 998244353;
		}		

		base = (base * 2) % 998244353;
	}

	printf("%I64d", res);

	return 0;
}