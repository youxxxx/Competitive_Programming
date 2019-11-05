#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	int tot[2] = { 0, };
	int i;
	int input;
	int cnt;
	priority_queue<int> pq;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		cnt = 0;

		while (!pq.empty())
		{
			pq.pop();
		}

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			while (!pq.empty() && pq.top() > input)
			{
				pq.pop();

				cnt++;
			}

			pq.push(input);
		}

		printf("%d\n", cnt);
	}

	return 0;
}