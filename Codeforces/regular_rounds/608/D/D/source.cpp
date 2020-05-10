#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second > b.second;
}

int main()
{
	int n, m, k;

	//freopen("input.txt", "r", stdin);
	
	scanf("%d %d %d", &n, &m, &k);

	vector<pair<pair<int, int>, int>> castle;
	int last[5001];
	vector<int> slack;

	for (int i = 0; i < n; i++)
	{
		last[i] = i;
	}

	int sum;

	sum = k;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		castle.push_back({ {a,b},c });

		if (sum < a)
		{
			printf("-1\n");

			return 0;
		}

		slack.push_back(sum - a);

		sum += b;
	}

	int rmin;

	rmin = slack.back();

	for (int i = n - 2; i >= 0; i--)
	{
		if (slack[i] < rmin)
		{
			rmin = slack[i];
		}

		else if (slack[i] > rmin)
		{
			slack[i] = rmin;
		}
	}

	vector<pair<int, int>> temp[5001],portal[5001];

	for (int i = 0; i < m; i++)
	{
		int u, v;

		scanf("%d %d", &u, &v);

		if (u - 1 > last[v - 1])
		{
			last[v - 1] = u - 1;
		}

		temp[u - 1].push_back({ v - 1, castle[v - 1].second });
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < temp[i].size(); j++)
		{
			if (last[temp[i][j].first] == i)
			{
				portal[i].push_back(temp[i][j]);
			}
		}

		if (last[i] == i)
		{
			portal[i].push_back({ i,castle[i].second });
		}

		sort(portal[i].begin(), portal[i].end(), func);
	}

	priority_queue<int> pq[2];

	vector<int> mm;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < slack[i + 1] && j < portal[i].size(); j++)
		{
			vector<int>::iterator ret;

			ret = lower_bound(mm.begin(), mm.end(), portal[i][j].second, greater<int>());

			mm.insert(ret, portal[i][j].second);

			//pq.push(portal[i][j].second);
		}

		/*
		while (pq.size() > slack[i + 1])
		{
			pq.pop();
		}
		*/
		while (mm.size() > slack[i + 1])
		{
			mm.pop_back();
		}
	}

	for (int j = 0; j < sum && j < portal[n - 1].size(); j++)
	{
		vector<int>::iterator ret;

		ret = lower_bound(mm.begin(), mm.end(), portal[n - 1][j].second, greater<int>());

		mm.insert(ret, portal[n - 1][j].second);
	}

	while (mm.size() > sum)
	{
		mm.pop_back();
	}

	int sol = 0;

	for (int i = 0; i < sum && i < mm.size(); i++)
	{
		sol += mm[i];
	}

	/*
	for (int j = 0; j < sum && j < portal[n - 1].size(); j++)
	{
		pq.push(portal[n - 1][j].second);
	}

	for (int i = 0; i < sum && !pq.empty(); i++)
	{
		sol += pq.top();

		pq.pop();
	}
	*/

	printf("%d\n", sol);

	return 0;
}