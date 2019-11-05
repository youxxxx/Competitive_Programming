#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int cases, tc;
	int visited[10001];
	int cnt[10001];
	vector<int> arr;
	int input;
	int i, n;
	int parity;
	int base;

	memset(visited, -1, sizeof(visited));

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		parity = 0;

		arr.clear();

		for (i = 0; i < 4 * n; i++)
		{
			scanf("%d", &input);

			if (visited[input] != tc)
			{
				visited[input] = tc;

				cnt[input] = 1;

				parity++;
			}

			else
			{
				if (++cnt[input] / 2)
				{
					arr.push_back(input);

					parity--;
				}

				else
				{
					parity++;
				}

				cnt[input] %= 2;
			}
		}

		if (parity)
		{
			printf("NO\n");

			continue;
		}

		sort(arr.begin(), arr.end());

		base = arr[0] * arr[2 * n - 1];

		for (i = 1; i < n; i++)
		{
			if (arr[i] * arr[2 * n - i - 1] != base)
			{
				break;
			}
		}

		if (i==n)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}