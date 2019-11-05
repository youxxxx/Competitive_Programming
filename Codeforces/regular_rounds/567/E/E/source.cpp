#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

bool func(const pair<pair<long long, long long>, pair<long long, long long>> &a, const pair<pair<long long, long long>, pair<long long, long long>> &b)
{
	return a.first.first < b.first.first;
}

bool func2(const pair<pair<long long, long long>, pair<long long, long long>> &a, const pair<pair<long long, long long>, pair<long long, long long>> &b)
{
	return a.first.second < b.first.second;
}

int main()
{
	vector<pair<pair<long long, long long>, pair<long long, long long>>> arr, cut;
	vector<vector<pair<pair<long long, long long>, pair<long long, long long>>>> proc[2];
	int n;
	int i;
	int j;
	long long x1, y1, x2, y2;
	long long lb, ub;
	int bit = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

		arr.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
	}

	sort(arr.begin(), arr.end(), func);

	lb = arr[0].first.first;
	ub = arr[0].second.first;

	cut.push_back(arr[0]);

	for (i = 1; i < n; i++)
	{
		if (arr[i].first.first >= ub)
		{
			if (cut.size() > 1)
			{
				proc[1].push_back(cut);
			}

			cut.clear();

			lb = arr[i].first.first;
			ub = arr[i].second.first;
		}

		else
		{
			if (arr[i].first.first < lb)
			{
				lb = arr[i].first.first;
			}

			if (arr[i].second.first > ub)
			{
				ub = arr[i].second.first;
			}
		}

		cut.push_back(arr[i]);
	}

	if (cut.size() > 1)
	{
		proc[1].push_back(cut);

		cut.clear();
	}

	while (!proc[!bit].empty())
	{
		cut.clear();

		proc[bit].clear();

		if (bit)
		{
			for (i = 0; i < proc[!bit].size(); i++)
			{
				cut.clear();

				sort(proc[!bit][i].begin(), proc[!bit][i].end(), func);

				lb = proc[!bit][i][0].first.first;
				ub = proc[!bit][i][0].second.first;

				cut.push_back(proc[!bit][i][0]);

				for (j = 1; j < proc[!bit][i].size(); j++)
				{
					if (proc[!bit][i][j].first.first >= ub)
					{
						if (cut.size() > 1)
						{
							proc[bit].push_back(cut);
						}

						cut.clear();

						lb = proc[!bit][i][j].first.first;
						ub = proc[!bit][i][j].second.first;
					}

					else
					{
						if (proc[!bit][i][j].first.first < lb)
						{
							lb = proc[!bit][i][j].first.first;
						}

						if (proc[!bit][i][j].second.first > ub)
						{
							ub = proc[!bit][i][j].second.first;
						}
					}

					cut.push_back(proc[!bit][i][j]);
				}

				if (cut.size() == proc[!bit][i].size())
				{
					printf("NO\n");

					return 0;
				}

				if (cut.size() > 1)
				{
					proc[bit].push_back(cut);

					cut.clear();
				}
			}
		}

		else
		{
			for (i = 0; i < proc[!bit].size(); i++)
			{
				cut.clear();

				sort(proc[!bit][i].begin(), proc[!bit][i].end(), func2);

				lb = proc[!bit][i][0].first.second;
				ub = proc[!bit][i][0].second.second;

				cut.push_back(proc[!bit][i][0]);

				for (j = 1; j < proc[!bit][i].size(); j++)
				{
					if (proc[!bit][i][j].first.second >= ub)
					{
						if (cut.size() > 1)
						{
							proc[bit].push_back(cut);
						}

						cut.clear();

						lb = proc[!bit][i][j].first.second;
						ub = proc[!bit][i][j].second.second;
					}

					else
					{
						if (proc[!bit][i][j].first.second < lb)
						{
							lb = proc[!bit][i][j].first.second;
						}

						if (proc[!bit][i][j].second.second  > ub)
						{
							ub = proc[!bit][i][j].second.second;
						}
					}

					cut.push_back(proc[!bit][i][j]);
				}

				if (cut.size() == proc[!bit][i].size())
				{
					printf("NO\n");

					return 0;
				}

				if (cut.size() > 1)
				{
					proc[bit].push_back(cut);

					cut.clear();
				}
			}
		}

		bit = !bit;
	}

	printf("YES\n");

	return 0;
}