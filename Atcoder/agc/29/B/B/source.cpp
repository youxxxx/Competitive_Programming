#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<long long> arr;
	long long input;
	long long res;
	long long lg;
	long long cnt = 0;
	vector<vector<pair<int, int>>> graph;
	int i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			res = arr[i] + arr[j];

			lg = (long long)log2((double)res);

			if ((long long)pow(2.0, lg) == res)
			{
				cnt++;
			}
		}
	}

	printf("%lld\n", cnt);

	return 0;
}