#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int path[64][64] = { 0, };
int cnt[64] = { 0, };
bool visited[64];

int dfs(int root, int cur, int parent)
{
	int i, j;

	for (i = 0; i < 64; i++)
	{
		if (i == cur || i == parent)
		{
			continue;
		}
	}
}

int main()
{
	vector<long long> arr, bits;
	long long input, temp;
	int i, j, k, l;
	int n;
	int lmin = 100;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		temp = input;

		bits.clear();
		
		for (j = 0; j < 64&&temp; j++)
		{
			if (temp % 2)
			{
				bits.push_back(j);

				cnt[j]++;
			}

			temp /= 2;
		}

		for (j = 0; j < bits.size(); j++)
		{
			for (k = 0; k < bits.size(); k++)
			{
				if (j == k)
				{
					continue;
				}

				path[bits[j]][bits[k]]++;
			}
		}
	}

	for (i = 0; i < 64; i++)
	{
		if (cnt[i])
		{
			for (j = 0; j < 64; j++)
			{
				if (i == j || !path[i][j])
				{
					continue;
				}

				if (path[i][j] >= 2 && (cnt[i] >= 3 || cnt[j] >= 3))
				{
					printf("3\n");

					return 0;
				}
			}

			for (j = 0; j < 64; j++)
			{
				visited[j] = false;
			}


		}
	}

	return 0;
}
