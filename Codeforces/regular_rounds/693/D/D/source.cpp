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
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		long long arr[200001];

		for (long long i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);
		}

		sort(&arr[0], &arr[n], greater<long long>());

		long long sum = 0;

		for (int i = 0; i < n; i++)
		{
			if (i % 2)
			{
				if (arr[i] % 2)
				{
					sum -= arr[i];
				}
			}

			else
			{
				if (!(arr[i] % 2))
				{
					sum += arr[i];
				}
			}
		}

		if (sum > 0)
		{
			printf("Alice\n");
		}

		else if (sum < 0)
		{
			printf("Bob\n");
		}

		else
		{
			printf("Tie\n");
		}
	}

	return 0;
}