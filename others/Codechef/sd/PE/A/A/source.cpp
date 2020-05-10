#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int t, z;
	int n, m;
	int i;
	vector<long long> a, b;
	long long input;

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

		if (n == 1 && m == 1 && a[0] == 1 && b[0] == 1)
		{
			printf("Bob\n");
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