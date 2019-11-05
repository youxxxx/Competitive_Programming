#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	vector<long long> a, b;
	int n;
	int i, j;
	long long input;
	long long cnt = 0;

	scanf("%d", &n);

	for (i = 0; i < n + 1; i++)
	{
		scanf("%lld", &input);

		a.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		b.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		if (a[i] >= b[i])
		{
			cnt += b[i];

			a[i] -= b[i];
		}

		else
		{
			cnt += a[i];

			b[i] -= a[i];

			cnt += b[i] < a[i + 1] ? b[i] : a[i + 1];

			a[i + 1] = b[i] > a[i + 1] ? 0 : a[i + 1] - b[i];
		}
	}

	printf("%lld\n", cnt);
	
	return 0;
}
