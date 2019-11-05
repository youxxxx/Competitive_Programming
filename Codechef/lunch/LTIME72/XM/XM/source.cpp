#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	int n, q;
	int i, j;
	int l, r;
	long long xorval;
	long long sum;
	vector<long long> arr;
	long long input;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &q);

		arr.clear();

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			arr.push_back(input);
		}

		for (i = 0; i < q; i++)
		{
			scanf("%d %d", &l, &r);

			xorval = 0;
			sum = 0;

			for (j = l; j <= r; j++)
			{
				sum += (xorval++) ^ arr[j - 1];
			}

			printf("%lld\n", sum);
		}
	}

	return 0;
}