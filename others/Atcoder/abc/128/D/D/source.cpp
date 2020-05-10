#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	int n, m;
	long long sum, lmax = 0;
	int i, j, k;
	vector<long long> jewel;
	long long input;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		jewel.push_back(input);
	}

	for (i = 1; i <= m && i <= n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			sum = 0;

			for (k = 0; k < j; k++)
			{
				pq.push(jewel[k]);

				sum += jewel[k];
			}

			for (k = 0; k < i - j; k++)
			{
				pq.push(jewel[n-1-k]);

				sum += jewel[n - 1 - k];
			}

			for (k = 0; k < i&&k < m - i; k++)
			{
				if (pq.top() >= 0)
				{
					break;
				}

				sum -= pq.top();

				pq.pop();
			}

			if (sum > lmax)
			{
				lmax = sum;
			}

			while (!pq.empty())
			{
				pq.pop();
			}
		}
	}

	printf("%lld\n", lmax);

	return 0;
}