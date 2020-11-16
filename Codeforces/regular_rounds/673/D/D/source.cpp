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

		long long arr[10001];

		long long sum = 0;

		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &arr[i]);

			sum += arr[i];
		}

		if (n == 1)
		{
			printf("0\n");

			continue;
		}

		if (sum%(long long)n)
		{
			printf("-1\n");

			continue;
		}

		const long long avg = sum / (long long)n;

		vector<pair<pair<int, int>,long long>> op;

		for (int i = 2; i <= n; i++)
		{
			const long long r = arr[i] % (long long)i;

			if (r)
			{
				op.push_back({ { 1,i }, i - r });
				z
				arr[1] -= i - r;
				arr[i] += i - r;
			}

			op.push_back({ { i,1 } , arr[i] / (long long)i });

			arr[1] += arr[i];
			arr[i] = 0;
		}

		for (int i = 2; i <= n; i++)
		{
			op.push_back({ {1,i},avg });
		}

		printf("%d\n", op.size());

		for (int i = 0; i < op.size(); i++)
		{
			printf("%d %d %lld\n", op[i].first.first, op[i].first.second, op[i].second);
		}
	}

 	return 0;
}