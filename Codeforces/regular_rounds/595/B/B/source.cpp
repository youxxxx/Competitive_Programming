#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int tc, cases;
	int i;
	int n;
	int input;
	int arr[200001];
	int sol[200001];
	queue<int> q;
	int cur;
	int loop;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		for (i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}

		memset(sol, -1, sizeof(sol));

		for (i = 1; i <= n; i++)
		{
			if (sol[i] == -1)
			{
				q.push(i);

				cur = arr[i];

				while (cur != i)
				{
					q.push(cur);

					cur = arr[cur];
				}

				loop = q.size();

				while (!q.empty())
				{
					sol[q.front()] = loop;

					q.pop();
				}
			}
		}

		for (i = 1; i <= n; i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0;
}