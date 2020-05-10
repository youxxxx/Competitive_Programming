#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

bool func(const pair<int, int> &a, const pair<int, int>&b)
{
	return a.first < b.first;
}

bool func2(const pair<int, int> &a, const pair<int, int>&b)
{
	return a.second < b.second;
}

int main()
{
	int t, tc;
	int i, j, k;
	vector<string> arr;
	char input[1000];
	string str;
	int n, m, l;
	int ptr[301];
	vector<int> num[2];
	char letter;
	int cur;
	bool empty;
	map<pair<int, int>, int> dp[2][2];
	map<pair<int, int>, int>::iterator it, ret, it2;
	pair<int, int> next1;
	int next2;
	vector<pair<int, int>> query, sol;
	int q;
	int ptr2;
	int cand;

	freopen("grading.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &tc);

	for (t = 0; t < tc; t++)
	{
		scanf("%d %d %d", &n, &m, &l);

		dp[0][0].clear();
		dp[0][1].clear();
		dp[1][0].clear();
		dp[1][1].clear();
		query.clear();
		sol.clear();
		num[0].clear();
		num[1].clear();
		arr.clear();

		for (i = 0; i < n; i++)
		{
			scanf("%s", input);
			str = input;

			arr.push_back(input);
		}

		for (i = 0; i < l; i++)
		{
			scanf("%d", &q);

			query.push_back(make_pair(q,i));
		}
		
		sort(query.begin(), query.end(), func);

		cur = 0;

		for (i = 0; i < 2; i++)
		{
			letter = i + 'A';

			for (j = 0; j < n; j++)
			{
				ptr[j] = m - 1;
			}

			empty = false;

			while (!empty)
			{
				cur = 0;

				empty = true;

				for (j = 0; j < n; j++)
				{
					if (ptr[j] != -1)
					{
						empty = false;

						while (ptr[j] != -1 && arr[j][ptr[j]] == letter)
						{
							cur++;

							ptr[j]--;
						}
					}
				}

				if (empty)
				{
					break;
				}

				if (num)
				{
					num[i].push_back(cur);
				}

				letter = 'B' - letter + 'A';
			}
		}

		for (i = 0; i < 2; i++)
		{
			dp[i][0][make_pair(num[i][0], 1)] = 1;

			for (j = 1; j < num[i].size(); j++)
			{
				for (it = dp[i][!(j % 2)].begin(); it != dp[i][!(j % 2)].end(); it++)
				{
					next1 = it->first;

					next1.second = 0;

					dp[i][j % 2][next1] = it->second;
				}

				for (it = dp[i][!(j % 2)].begin(); it != dp[i][!(j % 2)].end(); it++)
				{
					if (it->first.second == 1)
					{
						continue;
					}

					next1.first = it->first.first + num[i][j];

					next1.second = 1;

					ret = dp[i][j % 2].find(next1);

					if (ret == dp[i][j % 2].end())
					{
						dp[i][j % 2][next1] = it->second + 1;
					}

					else
					{
						if (it->second + 1 > ret->second)
						{
							ret->second = it->second + 1;
						}
					}
				}
			}

			next1.first = num[i][j];
			next1.second = 1;

			ret = dp[i][j % 2].find(next1);

			if (ret == dp[i][j % 2].end())
			{
				dp[i][j % 2][next1] = 1;
			}
		}

		for (i = 0; i < l; i++)
		{
			sol.push_back(make_pair(0, query[i].second));
		}

		for (i = 0; i < 2; i++)
		{
			it = dp[i][!(num[i].size() % 2)].begin();

			for (j = 0; j < l; j++)
			{
				while (it != dp[i][!(num[i].size() % 2)].end() && it->first.first <= query[j].first)
				{
					it++;
				}

				if (it != dp[i][!(num[i].size() % 2)].begin())
				{
					it2 = --it;

					while (it2 != dp[i][!(num[i].size() % 2)].begin() && it2->first.first == it->first.first)
					{
						it2--;
					}

					if (it2->first.first == it->first.first)
					{
						continue;
					}

					cand = it2->first.first;

					if (cand > sol[j].first)
					{
						sol[j].first = cand;
					}
				}
			}
		}

		sort(sol.begin(), sol.end(), func2);

		printf("Case #%d:", t + 1);

		for (i = 0; i < l; i++)
		{
			printf(" %d", sol[i].first);
		}

		printf("\n");
	}

	return 0;
}