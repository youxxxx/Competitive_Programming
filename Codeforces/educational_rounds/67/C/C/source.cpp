#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first < b.first || a.first == b.first&&a.second < b.second;
}

bool func2(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second < b.second;
}

int main()
{
	int n, m;
	int t, l, r;
	vector<pair<int, int>> good, bad, tot;
	int i, j;
	int lb, ub;
	int ptr;
	int sol[1001] = { 0, };
	int start = 100000;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &t, &l, &r);

		if (t == 1)
		{
			good.push_back(make_pair(l, r));
		}

		else
		{
			bad.push_back(make_pair(l, r));
		}
	}

	if (good.empty())
	{
		printf("YES\n");

		for (i = 0; i < n; i++)
		{
			printf("%d ", n - i);
		}

		return 0;
	}

	if (bad.empty())
	{
		printf("YES\n");

		for (i = 0; i < n; i++)
		{
			printf("1 ");
		}

		return 0;
	}

	sort(good.begin(), good.end(), func);
	sort(bad.begin(), bad.end(), func);

	/*
	for (i = 0; i < good.size(); i++)
	{
		for (j = good[i].first; j < good[i].second; j++)
		{
			sol[j] = 2;
		}
	}
	*/
	
	lb = good[0].first;
	ub = good[0].second;

	for (i = 1; i < good.size(); i++)
	{
		if (good[i].first > ub)
		{
			tot.push_back(make_pair(lb, ub));

			lb = good[i].first;
			ub = good[i].second;
		}

		else if(good[i].second>ub)
		{
			ub = good[i].second;
		}
	}

	tot.push_back(make_pair(lb, ub));

	for (i = 0; i < tot.size(); i++)
	{
		for (j = tot[i].first; j < tot[i].second; j++)
		{
			sol[j] = 2;
		}
	}
	

	j = 0;

	for (i = 0; i < bad.size(); i++)
	{
		for (j = bad[i].first; j < bad[i].second; j++)
		{
			if (sol[j] == 0 || sol[j] == 1)
			{
				sol[j] = 1;

				break;
			}
		}

		if (j == bad[i].second)
		{
			printf("NO\n");

			return 0;
		}
	}

	/*
	for (i = 0; i < bad.size(); i++)
	{
		while (j < tot.size())
		{
			if (bad[i].first >= tot[j].first&&bad[i].second <= tot[j].second)
			{
				printf("NO\n");

				return 0;
			}

			if (tot[j].second == n)
			{
				sol[tot[j].first + 1] = 1;

				break;
			}

			else if (bad[i].first >= tot[j].first&&bad[i].second > tot[j].second)
			{
				sol[tot[j].second + 1] = 1;

				break;
			}

			else if (bad[i].first < tot[j].first && bad[i].second <= tot[j].second)
			{
				if (bad[i].second > tot[j].first)
				{
					sol[tot[j].first] = 1;
				}

				else
				{
					sol[bad[i].first + 1] = 1;
				}

				break;
			}

			else
			{
				j++;
			}
		}

		if (j == tot.size())
		{
			if (bad[i].first >= tot.back().first && bad[i].second <= tot.back().second)
			{
				printf("NO\n");

				return 0;
			}

			sol[bad[i].second] = 1;
		}
	}
	*/

	printf("YES\n");

	for (i = 1; i <= n; i++)
	{
		printf("%d ", start);

		if (sol[i] == 1)
		{
			start--;
		}
	}

	return 0;
}