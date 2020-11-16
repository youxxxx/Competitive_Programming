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
		int n, m;

		scanf("%d %d", &n, &m);

		long long arr[300001];

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);
		}

		long long sol = 0;
		long long pos = 0;
		long long prev = 0;
		long long neg = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] > prev)
			{
				sol -= neg;

				neg = 0;

				pos = arr[i];
			}

			else
			{
				sol += pos;

				pos = 0;

				neg = arr[i];
			}

			prev = arr[i];
		}

		sol += pos;

		printf("%lld\n", sol);
	}

	return 0;
}