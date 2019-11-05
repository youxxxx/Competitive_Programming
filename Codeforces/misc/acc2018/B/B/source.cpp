#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int *cnt, *taken, *curhat, hatnum = 0;
	int input;
	int i, j;
	vector<int> arr;

	cnt = new int[100001];
	taken = new int[100001];
	curhat = new int[100001];

	scanf("%d", &n);

	for (i = 0; i <= n; i++)
	{
		cnt[i] = 0;
		taken[i] = 0;
		curhat[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		cnt[n - input]++;

		arr.push_back(n - input);
	}
/*
	if (n == 1)
	{
		if (arr[0] == 1)
		{
			printf("Possible\n1\n");
		}

		else
		{
			printf("Impossible\n");
		}

		return 0;
	}
*/
	for (i = 1; i <= n; i++)
	{
		if (cnt[i] % i)
		{
			break;
		}
	}

	if (i != n + 1)
	{
		printf("Impossible\n");
	}

	else
	{
		printf("Possible\n");

		for (j = 0; j < n; j++)
		{
			if (!(taken[arr[j]]++ % arr[j]))
			{	
				curhat[arr[j]] = ++hatnum;
			}

			printf("%d ", curhat[arr[j]]);
		}
	}

	return 0;
}