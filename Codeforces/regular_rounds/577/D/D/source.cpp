#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstring>

using namespace std;

long long n, m, k, q;
vector<long long> safe;
vector<long long>::iterator ptr, ladder;
map<long long, long long> list[2];
map<long long, long long>::iterator it, ret;
long long lmin[200001], lmax[200001];
long long target;
long long add;
long long cnt = 1;
long long i, j;
long long x, y, input;
long long val;
long long dist;

void proc()
{
	add += (long long)(abs(target - *ladder) + dist);

	ret = list[cnt % 2].find(*ladder);

	if (ret == list[cnt % 2].end())
	{
		list[cnt % 2][*ladder] = add + it->second;
	}

	else if (add + it->second < ret->second)
	{
		ret->second = add + it->second;
	}
}

void proc2() 
{
	ptr = lower_bound(safe.begin(), safe.end(), target);

	if (ptr == safe.end())
	{
		add = 0;

		ladder = ptr;

		ladder--;

		proc();
	}

	else if (*ptr == target)
	{
		add = 0;

		ladder = ptr;

		proc();
	}

	else if (ptr == safe.begin())
	{
		add = 0;

		ladder = ptr;

		proc();
	}

	else
	{
		add = 0;

		ladder = ptr;

		ladder--;

		proc();

		add = 0;

		ladder = ptr;

		proc();
	}
}

int main()
{
	long long sol = 999999999999999999, cand;
	int maxfloor = 1;

	memset(lmin, -1, sizeof(lmin));
	memset(lmax, -1, sizeof(lmax));

	//freopen("input.txt", "r", stdin);

	scanf("%lld %lld %lld %lld", &n, &m, &k, &q);

	for (i = 0; i < k; i++)
	{
		scanf("%lld %lld", &x, &y);

		if (lmin[x] == -1)
		{
			lmin[x] = lmax[x] = y;
		}

		else
		{
			if (y < lmin[x])
			{
				lmin[x] = y;
			}

			if (y > lmax[x])
			{
				lmax[x] = y;
			}
		}

		if (x > maxfloor)
		{
			maxfloor = x;
		}
	}

	for (i = 0; i < q; i++)
	{
		scanf("%lld", &input);
		 
		safe.push_back(input);
	}

	sort(safe.begin(), safe.end());

	list[0][1] = 0;

	if (maxfloor == 1)
	{
		printf("%d\n", lmax[1] - 1);

		return 0;
	}

	if (lmin[1] == -1)
	{
		list[0].clear();

		list[0][safe[0]] = safe[0] - 1;
	}

	for (i = 1; i < maxfloor; i++)
	{
		if (lmin[i] == -1)
		{
			continue;
		}

		list[cnt % 2].clear();

		for (it = list[!(cnt % 2)].begin(); it != list[!(cnt % 2)].end(); it++)
		{
			val = it->first;

			if (lmin[i] == lmax[i])
			{
				dist = abs(val - lmin[i]);

				target = lmin[i];

				proc2();
			}

			else
			{
				dist = abs(val - lmax[i]) + abs(lmax[i] - lmin[i]);

				target = lmin[i];

				proc2();

				dist = abs(val - lmin[i]) + abs(lmax[i] - lmin[i]);

				target = lmax[i];

				proc2();
			}
		}

		cnt++;
	}

	if (lmin[maxfloor] != -1)
	{
		for (it = list[!(cnt % 2)].begin(); it != list[!(cnt % 2)].end(); it++)
		{
			val = it->first;

			if (lmin[maxfloor] == lmax[maxfloor])
			{
				dist = abs(val - lmin[maxfloor]);

				cand = dist + it->second;

				if (cand < sol)
				{
					sol = cand;
				}
			}

			else
			{
				dist = abs(val - lmax[maxfloor]) + abs(lmax[maxfloor] - lmin[maxfloor]);

				cand = dist + it->second;

				if (cand < sol)
				{
					sol = cand;
				}

				dist = abs(val - lmin[maxfloor]) + abs(lmax[maxfloor] - lmin[maxfloor]);

				cand = dist + it->second;

				if (cand < sol)
				{
					sol = cand;
				}
			}
		}
	}

	else
	{
		for (it = list[!(cnt % 2)].begin(); it != list[!(cnt % 2)].end(); it++)
		{
			if (it->second < sol)
			{
				sol = it->second;
			}
		}
	}

	printf("%lld\n", sol + (long long)(maxfloor - 1));

	return 0;
}