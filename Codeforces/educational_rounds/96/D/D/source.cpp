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

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		char input[200001];

		scanf("%s", input);

		const string str = input;

		char prev = str[0];
		int cur = 0;
		int cnt = 0;
		int arr[200001];

		priority_queue<pair<int, int>> pq;

		for (int i = 0; i < n; i++)
		{
			if (str[i] != prev)
			{
				arr[cnt] = cur;

				if (cur > 1)
				{
					pq.push({ -cnt, cur });
				}

				cnt++;
				
				cur = 1;

				prev = str[i];

				continue;
			}

			cur++;
		}

		arr[cnt] = cur;

		if (cur > 1)
		{
			pq.push({ -cnt,cur });
		}

		cnt++;

		int ptr = cnt - 1;

		int sol = 0;

		for (int i = 0; i < cnt; i++)
		{
			while (!pq.empty() && -pq.top().first < i)
			{
				pq.pop();
			}

			if (pq.empty())
			{
				while (!arr[ptr] && ptr >= i)
				{
					ptr--;
				}

				if (ptr < i)
				{
					break;
				}

				arr[ptr]--;
			}

			else
			{
				const int idx = -pq.top().first;
				const int left = pq.top().second;
				pq.pop();

				arr[idx]--;

				if (left - 1 > 1)
				{
					pq.push({ -idx ,left - 1 });
				}
			}

			sol++;

			while (i < cnt && !arr[i])
			{
				i++;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}