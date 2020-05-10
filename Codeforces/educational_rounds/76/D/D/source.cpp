#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(pair<int, int> &a, pair<int, int> &b)
{
	return a.first > b.first || a.first == b.first&&a.second > b.second;
}

vector<int> monster;
vector<pair<int, int>> hero;

int bin_search(int lb, int ub, int target)
{
	int next;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	if (hero[next].first >= target)
	{
		return bin_search(next, ub, target);
	}

	return bin_search(lb, next, target);
}

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		monster.clear();
		hero.clear();

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			monster.push_back(input);
		}

		scanf("%d", &m);

		for (int i = 0; i < m; i++)
		{
			int input, input2;

			scanf("%d %d", &input, &input2);

			hero.push_back(make_pair(input, input2));
		}

		sort(hero.begin(), hero.end(), func);

		vector<int> lmax;
		int curmax = -1;

		lmax.clear();

		for (int i = 0; i < m; i++)
		{
			if (hero[i].second > curmax)
			{
				curmax = hero[i].second;
			}

			lmax.push_back(curmax);
		}

		bool valid = true;

		for (int i = 0; i < n; i++)
		{
			if (monster[i] > hero[0].first)
			{
				valid = false;

				break;
			}
		}

		if (!valid)
		{
			printf("-1\n");

			continue;
		}

		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			int j;

			if (i == n - 1)
			{
				cnt++;

				break;
			}

			for (j = i + 1; j < n; j++)
			{
				if (monster[j] > monster[i])
				{
					break;
				}
			}
			
			int idx;

			idx = bin_search(0, m, monster[i]);

			int maxtake = 0;

			maxtake = j;

			if (lmax[idx] < j - i)
			{
				i += lmax[idx] - 1;
			}

			else
			{
				if (j == n)
				{
					cnt++;
					
					break;
				}
				int prev;
				int curmax;
				int k;

				prev = j;
				curmax = monster[j];

				while (prev < n)
				{
					curmax = monster[prev];

					for (k = prev; k < n; k++)
					{
						if (monster[k] > curmax)
						{
							break;
						}
					}

					int nidx;

					nidx = bin_search(0, m, curmax);

					if (lmax[nidx] < k - i)
					{
						if (i + lmax[nidx] > maxtake)
						{
							maxtake = i + lmax[nidx];
						}

						i = maxtake - 1;

						break;
					}

					maxtake = k;

					prev = k;
				}

				if (prev >= n)
				{
					cnt++;

					break;
				}
			}

			cnt++;
		}

		printf("%d\n", cnt);
	}

	return 0;
}