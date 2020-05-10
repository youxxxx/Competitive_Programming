#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>

using namespace std;

class comp
{
public:
	bool operator() (const pair<int, int> &a, const pair<int, int> &b)
	{
		return a.first < b.first;
	}
};

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		int a[100001];
		int freq[100001];
		int b[100001];
		vector<int> list[100001];
		int c[100001];
		int add[100001];
		int left = 0;

		scanf("%d", &n);

		for (int i = 0; i <= n; i++)
		{
			freq[i] = b[i] = add[i] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);

			if (a[i] == -1)
			{
				left++;
			}

			else
			{
				freq[a[i]]++;
			}
		}

		for (int i = 0; i < n; i++)
		{
			b[freq[i]]++;

			list[freq[i]].push_back(i);
		}

		int tot = 0;

		for (int i = 0; i <= n; i++)
		{
			scanf("%d", &c[i]);

			tot += c[i] * i;
		}

		if (tot != n)
		{
			printf("impossible\n");

			continue;
		}

		int cnt = 0;

		bool invalid = false;

		for (int i = 0; i < n; i++)
		{
			cnt += b[i];

			cnt -= c[i];

			if (cnt < 0)
			{
				invalid = true;

				break;
			}
		}

		if (invalid)
		{
			printf("impossible\n");

			continue;
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j < list[i].size(); j++)
			{
				pq.push({ list[i][j], i });
			}

			for (int j = 0; j < c[i]; j++)
			{
				add[pq.top().first] += i - pq.top().second;

				pq.pop();
			}
		}

		int ptr = 0;

		for (int i = 0; i < n; i++)
		{
			if (a[i] == -1)
			{
				while (ptr < n&&add[ptr] == 0)
				{
					ptr++;
				}

				a[i] = ptr;

				add[ptr]--;
			}
		}

		for (int i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}

		printf("\n");
	}

	return 0;
}