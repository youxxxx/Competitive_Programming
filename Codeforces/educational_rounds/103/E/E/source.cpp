#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	map<string, int> list;

	const int ub = (int)pow(2.0, k);

	for (int i = 1; i <= n; i++)
	{
		char input[10];

		scanf("%s", input);
		const string str = input;

		list[str] = i;
	}

	/*
	vector<int> anc[100001], dec[100001];

	for (map<string, int>::iterator it = list.begin(); it != list.end(); it++)
	{
		const string base = it->first;

		const int idx = it->second;

		for (int i = 1; i < ub; i++)
		{
			int bit[4];

			int temp = i;

			for (int j = 0; j < k; j++)
			{
				bit[j] = temp % 2;

				temp /= 2;
			}

			string cur = base;

			for (int j = 0; j < k; j++)
			{
				if (bit[j])
				{
					cur[j] = '_';
				}
			}

			if (cur != base)
			{
				map<string, int>::iterator ret = list.find(cur);

				if (ret != list.end())
				{
					anc[idx].push_back(ret->second);
					dec[ret->second].push_back(idx);
				}
			}
		}
	}
	*/

	vector<int> out[100001];
	int in[100001] = { 0, };

	for (int i = 0; i < m; i++)
	{
		char input[10];
		int idx;

		scanf("%s %d", input, &idx);
		const string base = input;
		bool found = false;

		for (int mask = 0; mask < ub; mask++)
		{
			int bit[4];

			int temp = mask;

			for (int j = 0; j < k; j++)
			{
				bit[j] = temp % 2;

				temp /= 2;
			}

			string cur = base;

			for (int j = 0; j < k; j++)
			{
				if (bit[j])
				{
					cur[j] = '_';
				}
			}

			map<string, int>::iterator ret = list.find(cur);

			if (ret != list.end())
			{
				if (ret->second == idx)
				{
					found = true;

					continue;
				}

				/*
				for (int j = 0; j < (int)out[ret->second].size(); j++)
				{
					if (out[ret->second][j] == idx)
					{
						printf("NO\n");

						return 0;
					}
				}
				*/

				out[idx].push_back(ret->second);
				in[ret->second]++;
			}
		}

		if (!found)
		{
			printf("NO\n");

			return 0;
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (!in[i])
		{
			q.push(i);
		}
	}

	vector<int> sol;

	while (!q.empty())
	{
		const int cur = q.front();
		q.pop();
		sol.push_back(cur);

		for (int i = 0; i < (int)out[cur].size(); i++)
		{
			if (!(--in[out[cur][i]]))
			{
				q.push(out[cur][i]);
			}
		}
	}

	if ((int)sol.size() != n)
	{
  		printf("NO\n");

		return 0;
	}

	printf("YES\n");

	for (int i = 0; i < n; i++)
	{
		printf("%d ", sol[i]);
	}

	printf("\n");

	return 0;
}