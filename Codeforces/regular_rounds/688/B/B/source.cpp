#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

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

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);
		}

		long long tot = 0;
		long long subt = 0;

		subt = max(subt, abs(arr[0] - arr[1]));

		for (int i = 1; i < n - 1; i++)
		{
			tot += abs(arr[i] - arr[i - 1]);

			const long long v1 = abs(arr[i] - arr[i - 1]);
			const long long v2 = abs(arr[i] - arr[i + 1]);

			const long long s1 = arr[i] == arr[i - 1] ? 0 : (arr[i] - arr[i - 1]) / abs(arr[i] - arr[i - 1]);
			const long long s2 = arr[i] == arr[i + 1] ? 0 : (arr[i] - arr[i + 1]) / abs(arr[i] - arr[i + 1]);

			if (!s1 || !s2 || s1 == s2)
			{
				const long long cand = min(v1, v2) * 2;

				subt = max(subt, cand);
			}
		}

		tot += abs(arr[n - 1] - arr[n - 2]);

		subt = max(subt, abs(arr[n - 1] - arr[n - 2]));

		printf("%lld\n", tot - subt);
	}

	return 0;
}