#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	int n, m;
	int i;
	vector<long long> a, b;
	long long input;
	int index;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &m);

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			a.push_back(input);
		}

		for (i = 0; i < m; i++)
		{
			scanf("%lld", &input);

			b.push_back(input);
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		index = -1;
		while (++index < n && !a[index]);
		a.erase(a.begin() + 0, a.begin() + index);
		n -= index;

		index = -1;
		while (++index < m && !b[index]);
		b.erase(b.begin() + 0, b.begin() + index);
		m -= index;

		if (n == m)
		{
			for (i = 0; i < n; i++)
			{
				if (a[i] != b[i])
				{
					break;
				}
			}

			if (i == n)
			{
				printf("Bob\n");
			}

			else
			{
				printf("Alice\n");
			}
		}

		else
		{
			printf("Alice\n");
		}

		a.clear();
		b.clear();
	}

	return 0;
}