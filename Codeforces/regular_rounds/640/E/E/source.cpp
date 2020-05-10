#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int arr[8000];
		bool sp[8001] = { 0, };

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		for (int i = 0; i < n - 1; i++)
		{
			int sum = arr[i] + arr[i + 1];

			if (sum > n)
			{
				continue;
			}

			sp[sum] = true;

			for (int j = i + 2; j < n; j++)
			{
				sum += arr[j];

				if (sum > n)
				{
					break;
				}

				sp[sum] = true; 
			}
		}

		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			cnt += sp[arr[i]];
		}

		printf("%d\n", cnt);
	}

	return 0;
}