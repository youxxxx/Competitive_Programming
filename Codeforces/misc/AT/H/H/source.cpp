#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	int n, q;
	int max = 0;
	vector<int> prime;
	vector<int> arr;
	vector<bool*> mask;
	bool* sheet;
	int input, cnt, min;
	int i, j, k;
	int l, r;
	int **dist, **pdist;

	bool flag;

	scanf("%d %d", &n, &q);

	dist = new int*[n];
	pdist = new int*[n];

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (input > max)
		{
			max = input;
		}

		arr.push_back(input);

		dist[i] = new int[n];
		pdist[i] = new int[n];
	}

	prime.push_back(2);

	for (i = 3; i <= max; i+=2)
	{
		for (j = 0; j < prime.size(); j++)
		{
			if (!(i%prime[j]))
			{
				break;
			}
		}

		if (j == prime.size())
		{
			prime.push_back(i);
		}
	}

	for (i = 0; i < n; i++)
	{
		sheet = new bool[prime.size()];

		for (j = 0; j < prime.size(); j++)
		{
			sheet[j] = false;
		}

		mask.push_back(sheet);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < prime.size(); j++)
		{
			flag = false;

			if (arr[i] < prime[j])
			{
				break;
			}

			while (arr[i] >= prime[j] && !(arr[i] % prime[j]))
			{
				arr[i] /= prime[j];

				flag = !flag;
			}

			mask[i][j] = flag;
		}
	}

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			cnt = 0;

			for (k = 0; k < prime.size(); k++)
			{
				cnt += (mask[i][k] && !mask[j][k] || !mask[i][k] && mask[j][k]);
			}

			dist[i][j] = dist[j][i] = cnt;
		}
	}

	for (i = 0; i < q; i++)
	{
		scanf("%d %d", &l, &r);

		l--;
		r--;

		min = prime.size();

		for (j = l; j <= r; j++)
		{
			for (k = j + 1; k <= r; k++)
			{
				if (dist[j][k] < min)
				{
					min = dist[j][k];
				}
			}
		}

		printf("%d\n", min);
	}

	return 0;
}