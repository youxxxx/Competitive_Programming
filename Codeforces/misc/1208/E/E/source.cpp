#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	long long n;
	long long w;
	long long m;
	vector<long long> arr;
	priority_queue<pair<long long, long long>> pq;
	long long input;
	long long i, j;
	long long lmax[1000000] = { 0, };
	long long add;

	scanf("%lld %lld", &n, &w);

	for (i = 0; i < n; i++)
	{
		arr.clear();

		scanf("%lld", &m);

		for (j = 0; j < m; j++)
		{
			scanf("%lld", &input);

			arr.push_back(input);
		}

		if (m == w)
		{
			for (j = 0; j < m; j++)
			{
				lmax[j] += arr[j];
			}
		}

		else
		{
			while (!pq.empty())
			{
				pq.pop();
			}

			for (j = 0; j < w; j++)
			{
				if (j < m)
				{
					pq.push(make_pair(arr[j], w - m + j));
				}

				while (!pq.empty() && pq.top().second < j)
				{
					pq.pop();
				}
				
				add = pq.top().first;

				if (add < 0 && (j >= m || j < w - m))
				{
					add = 0;
				}

				lmax[j] += add;
			}
		}
	}

	for (i = 0; i < w; i++)
	{
		printf("%lld ", lmax[i]);
	}

	return 0;
}