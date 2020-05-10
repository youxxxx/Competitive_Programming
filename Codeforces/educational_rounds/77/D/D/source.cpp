#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int n, m, k, t;
vector<int> soldier;
vector<pair<pair<int, int>, int>> trap;

bool func(const pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
	return a.second > b.second;
}

int bin_search(int lb, int ub)
{
	int next;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	int pwr, sol;
	int left = -1, right = -2;

	pwr = soldier[next];

	sol = m + 1;

	for (int i = 0; i < k; i++)
	{
		if (pwr >= trap[i].second)
		{
			continue;
		}

		if (left == -1)
		{
			left = trap[i].first.first;
			right = trap[i].first.second;
		}

		else
		{
			if (trap[i].first.first > right + 1)
			{
				sol += (right - left + 1) * 2;

				left = trap[i].first.first;
				right = trap[i].first.second;
			}

			else if (trap[i].first.second > right)
			{
				right = trap[i].first.second;
			}
		}
	}

	sol += (right - left + 1) * 2;

	if (sol <= t)
	{
		return bin_search(next, ub);
	}

	return bin_search(lb, next);
}

int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d %d", &n, &m, &k, &t);

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		soldier.push_back(input);
	}

	sort(soldier.begin(), soldier.end(), greater<int>());

	for (int i = 0; i < k; i++)
	{
		int l, r, d;

		scanf("%d %d %d", &l, &r, &d);

		trap.push_back({ {l,r},d });
	}

	sort(trap.begin(), trap.end());

	printf("%d\n", bin_search(-1, n) + 1);

	return 0;
}