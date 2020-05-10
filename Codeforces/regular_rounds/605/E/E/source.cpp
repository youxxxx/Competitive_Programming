#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

int n;

bool safe(int x)
{
	return x >= 0 && x < n;
}
int main()
{
	bool visited[200001] = { 0, };
	int sol[200001];
	vector<int> arr;
	memset(sol, -1, sizeof(sol));
	vector<int> ptr[200001];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		arr.push_back(input);

		int next;

		next = i - arr[i];

		if (safe(next))
		{
			ptr[next].push_back(i);
		}

		next = i + arr[i];

		if (safe(next))
		{
			ptr[next].push_back(i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int next;

		next = i - arr[i];

		if (safe(next) && arr[i] % 2 != arr[next] % 2)
		{
			visited[i] = true;

			sol[i] = 1;
		}

		next = i + arr[i];

		if (safe(next) && arr[i] % 2 != arr[next] % 2)
		{
			visited[i] = true;

			sol[i] = 1;
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		if (visited[i])
		{
			q.push({ i,1 });
		}
	}

	while (!q.empty())
	{
		int cur;
		int cnt;

		cur = q.front().first;
		cnt = q.front().second;
		q.pop();

		for (int i = 0; i < ptr[cur].size(); i++)
		{
			int next;

			next = ptr[cur][i];

			if (!visited[next])
			{
				visited[next] = true;

				sol[next] = cnt + 1;

				q.push({ next, cnt + 1 });
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", sol[i]);
	}

	return 0;
}