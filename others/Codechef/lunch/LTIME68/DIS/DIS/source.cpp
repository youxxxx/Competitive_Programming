#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int t, z;
	int n, i;
	long long input;
	vector<long long> a, b;
	long long min;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);
			a.push_back(input);
		}

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);
			b.push_back(input);
		}

		if (a[0] || b[n - 1] || a[n - 1] != b[0] || !a[n-1] || !b[0])
		{
			printf("No\n");

			a.clear();
			b.clear();

			continue;
		}

		min = b[0];

		for (i = 1; i < n - 1; i++)
		{
			if (a[i] + b[i] < min)
			{
				min = a[i] + b[i];
			}

			if (!a[i] || !b[i])
			{
				break;
			}
		}

		if (i != n - 1)
		{
			printf("No\n");

			a.clear();
			b.clear();

			continue;
		}

		for (i = 1; i < n - 1; i++)
		{
			if (a[i] + b[i] < b[0] || a[i] + min < b[i] || b[i] + min < a[i])
			{
				break;
			}
		}

		if (i != n - 1)
		{
			printf("No\n");
		}

		else
		{
			printf("Yes\n");
		}

		a.clear();
		b.clear();
	}

	return 0;
}