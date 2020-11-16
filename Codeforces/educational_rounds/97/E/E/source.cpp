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
	freopen("input.txt", "r", stdin);

	int arr[500001];

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);

		arr[i] -= i;
	}

	if (!m)
	{
		vector<int> lis = { 0, };

		for (int j = 0; j < n; j++)
		{
			vector<int>::iterator ret = lower_bound(lis.begin(), lis.end(), arr[j]);

			if (ret == lis.end())
			{
				lis.push_back(arr[j]);
			}

			else
			{
				*ret = arr[j];
			}
		}

		printf("%d\n", n - (lis.size() - 1));

		return 0;
	}

	int b[500001];

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);

		b[i]--;
	}

	for (int i = 0; i < m - 1; i++)
	{
		if (arr[b[i+1]] < arr[b[i]])
		{
			printf("-1\n");

			return 0;
		}
	}

	int sol = 0;

	{
		vector<int> lis = { 0, };

		for (int j = 0; j < b[0]; j++)
		{
			if (arr[j] > arr[b[0]])
			{
				continue;
			}

			vector<int>::iterator ret = lower_bound(lis.begin(), lis.end(), arr[j]);

			if (ret == lis.end())
			{
				lis.push_back(arr[j]);
			}

			else
			{
				*ret = arr[j];
			}
		}

		sol += b[0] - (lis.size() - 1);
	}

	for (int i = 0; i < m - 1; i++)
	{
		vector<int> lis = {arr[b[i]]};

		for (int j = b[i] + 1; j < b[i + 1]; j++)
		{
			if (arr[j] < arr[b[i]] || arr[j] > arr[b[i + 1]])
			{
				continue;
			}

			vector<int>::iterator ret = lower_bound(lis.begin(), lis.end(), arr[j]);

			if (ret == lis.end())
			{
				lis.push_back(arr[j]);
			}

			else
			{
				*ret = arr[j];
			}
		}

		sol += b[i + 1] - b[i] + 1 - (lis.size() - 1);
	}

	{
		vector<int> lis = { 0, };

		for (int j = b[m-1] + 1; j < n; j++)
		{
			if (arr[j] < arr[b[m - 1]])
			{
				continue;
			}

			vector<int>::iterator ret = lower_bound(lis.begin(), lis.end(), arr[j]);

			if (ret == lis.end())
			{
				lis.push_back(arr[j]);
			}

			else
			{
				*ret = arr[j];
			}
		}

		sol += n - 1 - b[m - 1] - (lis.size() - 1);
	}

	printf("%d\n", sol);

	return 0;
}