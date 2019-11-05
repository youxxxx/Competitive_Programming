#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int t, z;
	int n, i;
	long long k, m;
	vector<long long> arr;
	long long numk, numm;
	long long input;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %lld %lld", &n, &k, &m);

		numk = 0;
		numm = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			if (input == k)
			{
				numk++;
			}

			else if (input == m)
			{
				numm++;
			}

			else
			{
				arr.push_back(input);
			}
		}

		for (i = 0; i < numk; i++)
		{
			printf("%lld ", k);
		}

		for (i = 0; i < arr.size(); i++)
		{
			printf("%lld ", arr[i]);
		}

		for (i = 0; i < numm; i++)
		{
			printf("%lld ", m);
		}

		printf("\n");

		arr.clear();
	}

	return 0;
}