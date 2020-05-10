#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<set>

using namespace std;

int main()
{
	long long t, z;
	long long k, n;
	/*
	long long cnt[300001];
	long long cnt2[300001];
	long long cnt3[300001];
	long long mid[300001];
	long long lmin[300001];
	long long *cnt;
	long long *cnt2;
	long long *cnt3;
	long long *mid;
	*/
	vector<long long> *loc;
	//long long *lmin;
	long long lmin;
	long long gmin;
	bool valid;
	long long base;
	long long i, j;
	vector<long long> arr;
	long long input;
	set<long long> nums;
	set<long long>::iterator it;

	//freopen("input.txt", "r", stdin);

	scanf("%lld", &t);
	/*
	cnt = new long long[300001];
	cnt2 = new long long[300001];
	cnt3 = new long long[300001];
	mid = new long long[300001];
	lmin = new long long[300001];
	*/
	loc = new vector<long long>[300001];

	for (z = 0; z < t; z++)
	{
		scanf("%lld %lld", &n, &k);

		valid = false;

		gmin = n*n;

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			arr.push_back(input);

			loc[input].push_back(i);

			nums.insert(input);

			if (loc[input].size() >= k)
			{
				valid = true;
			}
		}

		if (!valid)
		{
			printf("-1\n");

			for (it = nums.begin(); it != nums.end(); it++)
			{
				loc[*it].clear();
			}

			nums.clear();
			arr.clear();

			continue;
		}

		for (it = nums.begin(); it != nums.end(); it++)
		{
			lmin = 0;

			if (loc[*it].size() >= k)
			{
				for (i = 0; i < k; i++)
				{
					lmin += abs(loc[*it][k / 2] - loc[*it][i]) - abs(i - k / 2);
				}

				if (lmin < gmin)
				{
					gmin = lmin;
				}

				for (i = 1; i + k <= loc[*it].size(); i++)
				{
					lmin -= abs(loc[*it][i + k / 2 - 1] - loc[*it][i - 1]);
					lmin += abs(loc[*it][i + k / 2] - loc[*it][i + k - 1]) + !(k % 2) * abs(loc[*it][i + k / 2] - loc[*it][i + k / 2 - 1]);

					if (lmin < gmin)
					{
						gmin = lmin;
					}
				}
			}
		}

		printf("%lld\n", gmin);

		for (it = nums.begin(); it != nums.end(); it++)
		{
			loc[*it].clear();
		}

		nums.clear();
		arr.clear();
	}

	return 0;
}