#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;
	int out[200001];
	int in[200001] = { 0, };
	int last[200001] = { 0, };
	vector<int> back[200001];
	long long val[200001];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &val[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &out[i]);

		if (out[i] != -1)
		{
			last[i]++;

			back[out[i]].push_back(i);

			in[out[i]]++;
		}
	}

	queue<int> q, wait;

	vector<int> sol;

	long long sum = 0;

	for (int i = 1; i <= n; i++)
	{
		if (!in[i])
		{
			q.push(i);
		}
	}

	bool visited[200001] = { 0, };

	while (!q.empty())
	{
		const int cur = q.front();
		q.pop();

		if (val[cur] < 0)
		{
			wait.push(cur);
		}

		else
		{
			visited[cur] = true;

			sum += val[cur];

			sol.push_back(cur);

			for (int i = 0; i < back[cur].size(); i++)
			{
				const int next = back[cur][i];

				last[next]--;
			}

			if (out[cur] != -1)
			{
				val[out[cur]] += val[cur];
			}
		}

		if (out[cur] != -1)
		{
			if (!(--in[out[cur]]))
			{
				q.push(out[cur]);
			}
		}
	}

	queue<int> q2;

	while (!wait.empty())
	{
		const int cur = wait.front();
		wait.pop();

		if (!last[cur])
		{
			q2.push(cur);
		}
	}

	while (!q2.empty())
	{
		const int cur = q2.front();
		q2.pop();

		visited[cur] = true;

		sum += val[cur];
		sol.push_back(cur);

		for (int i = 0; i < back[cur].size(); i++)
		{
			const int next = back[cur][i];

			if (!visited[next])
			{
				if (!(--last[next]))
				{
					q2.push(next);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			sum += val[i];

			sol.push_back(i);
		}
	}

	printf("%lld\n", sum);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", sol[i]);
	}

	printf("\n");

	return 0;
}