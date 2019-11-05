#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>

using namespace std;

bool func(pair<long long, long long> &a, pair<long long, long long> &b)
{
	return a.first < b.first;
}

class comp
{
public:
	bool operator() (pair<long long, long long> &a, pair<long long, long long> &b) const
	{
		return a.second < b.second;
	}
};

int main()
{
	int n, m;
	int i, j;
	long long l, r;
	vector<pair<long long, long long>> interv, cover;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, comp> pq;
	int cnt = 0;
	long long last;
	long long cur = 0;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld", &l, &r);

		interv.push_back(pair<long long, long long>(l, r));
	}

	for (i = 0; i < m; i++)
	{
		scanf("%lld %lld", &l, &r);

		cover.push_back(pair<long long, long long>(l, r));
	}

	sort(interv.begin(), interv.end(), func);
	sort(cover.begin(), cover.end(), func);

	l = cover[0].first;
	r = cover[0].second;

	j = 0;

	for (i = 1; i < m; i++)
	{
		if (cover[i].first < r)
		{
			if (cover[i].second > r)
			{
				r = cover[i].second;
			}

			continue;
		}

		while (l != r)
		{
			while (!pq.empty() && pq.top().second < l)
			{
				pq.pop();
			}

			while (j < n&&interv[j].first <= l)
			{
				pq.push(interv[j]);

				j++;
			}

			cur = 0;

			if (pq.top().second <= l)
			{
				printf("-1\n");

				break;
			}

			l = pq.top().second < r ? pq.top().second : r;
		}

		l = cover[i].first;
		r = cover[i].second;
	}

	while (l != r)
	{
		while (!pq.empty() && pq.top().second < l)
		{
			pq.pop();
		}

		while (j < n&&interv[j].first <= l)
		{
			pq.push(interv[j]);

			j++;
		}

		cnt++;

		cur = 0;

		if (pq.top().second <= l)
		{
			printf("-1\n");

			break;
		}

		l = pq.top().second < r ? pq.top().second : r;
	}

	printf("%d\n", cnt);

	return 0;
}