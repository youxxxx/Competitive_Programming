#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int n, m;
	char input[2000];
	int val[2000];
	int cnt[1000][5] = { 0, };
	int lmax;
	string str;
	vector<string> arr;
	int i, j;
	int sum = 0;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		arr.push_back(input);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d", &val[i]);
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cnt[j][arr[i][j] - 'A']++;
		}
	}

	for (i = 0; i < m; i++)
	{
		lmax = 0;

		for (j = 0; j < 5; j++)
		{
			if (cnt[i][j] > lmax)
			{
				lmax = cnt[i][j];
			}
		}

		sum += lmax*val[i];
	}

	printf("%d\n", sum);

	return 0;
}