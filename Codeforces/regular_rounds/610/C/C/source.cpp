#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n, t, a, b;
		vector<long long> arr;
		vector<pair<long long, long long>> prob;
		long long cnt[2] = { 0, };

		scanf("%lld %lld %lld %lld", &n, &t, &a, &b);

		for (long long i = 0; i < n; i++)
		{
			long long input;
			scanf("%lld", &input);
			arr.push_back(input);

			cnt[input]++;
		}

		for (long long i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);
			prob.push_back({ input,arr[i] });
		}

		if (a*cnt[0] + b*cnt[1] <= t)
		{
			printf("%lld\n", cnt[0] + cnt[1]);

			continue;
		}

		sort(prob.begin(), prob.end());

		long long cur[2] = { 0, };

		cur[prob[0].second]++;

		vector < pair<long long, pair<long long, long long>>> list;

		long long prev;

		prev = prob[0].first;

		for (long long i = 1; i < n; i++)
		{
			if (prob[i].first != prev)
			{
				list.push_back({ prev,{cur[0],cur[1]} });
			}

			cur[prob[i].second]++;
			prev = prob[i].first;
		}

		list.push_back({ prev,{ cur[0],cur[1] } });

		if (a*cnt[0] + b*cnt[1] <= t)
		{
			printf("%lld\n", cnt[0] + cnt[1]);

			continue;
		}

		long long lmax = 0;
		long long base;

		base = list[0].first - 1;

		if (base > 0)
		{
			long long cand = 0;
			long long subt;

			subt = cnt[0] < base / a ? cnt[0] : base / a;

			base -= a*subt;

			cand += subt;

			subt = cnt[1] < base / b ? cnt[1] : base / b;

			base -= b*subt;

			cand += subt;

			if (cand > lmax)
			{
				lmax = cand;
			}
		}

		for (long long i = 1; i < list.size(); i++)
		{
			long long left[2];

			left[0] = cnt[0] - list[i - 1].second.first;
			left[1] = cnt[1] - list[i - 1].second.second;

			long long cand;

			cand = list[i - 1].second.first + list[i - 1].second.second;

			base = list[i].first - 1;

			base -= list[i - 1].second.first*a + list[i - 1].second.second*b;

			if (base >= 0)
			{
				long long subt;

				subt = left[0] < base / a ? left[0] : base / a;

				base -= a*subt;

				cand += subt;

				subt = left[1] < base / b ? left[1] : base / b;

				base -= b*subt;

				cand += subt;

				if (cand > lmax)
				{
					lmax = cand;
				}
			}
		}

		printf("%lld\n", lmax);
	}

	return 0;
}