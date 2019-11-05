#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int n, m;
	int i;
	int p, q, temp;
	vector<long long> arr;
	long long acc[100001];
	long long input;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		arr.clear();

		scanf("%d %d", &n, &m);

		arr.push_back(0);

		for (i = 0; i < n - 1; i++)
		{
			scanf("%lld", &input);

			arr.push_back(input);
		}

		acc[0] = 0;
		acc[1] = 0;

		for (i = 2; i <= n; i += 2)
		{
			acc[i] = acc[i - 2] + arr[i - 1];
		}

		for (i = 3; i <= n; i += 2)
		{
			acc[i] = acc[i - 2] + arr[i - 1];
		}

		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &p, &q);

			if (p > q)
			{
				temp = p;
				p = q;
				q = temp;
			}

			if ((q - p) % 2)
			{
				printf("%lld\n", acc[p] - acc[q - 1] - (acc[p - 1] - acc[q]));
			}

			else
			{
				printf("UNKNOWN\n");
			}
		}
	}

	return 0;
}