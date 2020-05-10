#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		vector<pair<long long, long long>> interv;

		long long n;

		scanf("%lld", &n);

		for (long long i = 0; i < n; i++)
		{
			long long l, r;

			scanf("%lld %lld", &l, &r);

			interv.push_back({ l,r });
		}

		sort(interv.begin(), interv.end());

		long long curmax;

		long long space[200001];

		space[0] = 1;

		long long lmax[200001];

		lmax[0] = interv[0].second;

		curmax = interv[0].second;

		for (long long i = 1; i < n; i++)
		{
			space[i] = space[i - 1];

			if (interv[i].first > curmax)
			{
				space[i]++;
			}

			if (interv[i].second > curmax)
			{
				curmax = interv[i].second;
			}

			lmax[i] = curmax;
		}

		priority_queue<pair<long long, long long>> pq;

		long long sol;

		sol = space[n - 2];

		vector<pair<long long, long long>> cur;

		cur.push_back(interv[n - 1]);

		for (long long i = n - 2; i >= 1; i--)
		{
			vector<pair<long long, long long>>::iterator ret;

			ret = upper_bound(cur.begin(), cur.end(), pair<long long, long long>(lmax[i - 1], 1000000001));

			if (space[i - 1] + (cur.end() - ret) > sol)
			{
				sol = space[i - 1] + (cur.end() - ret);
			}

			long long temp;

			ret = upper_bound(cur.begin(), cur.end(), pair<long long, long long>(interv[i].second, 1000000001));

			if (ret == cur.begin())
			{
				temp = interv[i].second;
			}

			else
			{
				vector<pair<long long, long long>>::iterator ret2;

				ret2 = ret;

				ret2--;

				temp = ret2->second;
			}

			cur.erase(cur.begin(), ret);

			cur.insert(cur.begin(), { interv[i].first,temp });
		}

		long long smax;

		smax = interv[1].second;

		long long cnt = 1;

		for (long long i = 2; i < n; i++)
		{
			if (interv[i].first > smax)
			{
				cnt++;
			}

			if (interv[i].second > smax)
			{
				smax = interv[i].second;
			}
		}

		if (cnt > sol)
		{
			sol = cnt;
		}

		printf("%lld\n", sol);
	}

	return 0;
}