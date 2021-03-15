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

		pair<long long, int> arr[200001];
		long long acc[200001];

		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &arr[i].first);

			arr[i].second = i;

			acc[i] = acc[i - 1] + arr[i].first;
		}

		sort(&arr[1], &arr[n + 1]);

		acc[0] = 0;

		for (int i = 1; i <= n; i++)
		{
			acc[i] = acc[i - 1] + arr[i].first;
		}

		int ub = n;

		/*
		for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
		{
			long long sum = acc[next];

			bool check = true;

			for (int i = next + 1; i <= n; i++)
			{
				if (sum < arr[i].first)
				{
					check = false;

					break;
				}

				sum += arr[i].first;
			}

			if (check)
			{
				ub = next;
			}

			else
			{
				lb = next;
			}
		}
		*/

		for (int i = n - 1; i >= 1; i--)
		{
			if (acc[i] < arr[i + 1].first)
			{
				break;
			}

			ub = i;
		}

		const long long val = arr[ub].first;

		while (ub > 1 && arr[ub - 1].first == val)
		{
			ub--;
		}

		vector<int> sol;

		for (int i = ub; i <= n; i++)
		{
			sol.push_back(arr[i].second);
		}

		printf("%d\n", (int)sol.size());

		sort(sol.begin(), sol.end());

		for (int i = 0; i < (int)sol.size(); i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0; 
}