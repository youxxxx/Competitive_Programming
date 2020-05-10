#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		vector<int> arr(2000);
		int n;

		scanf("%d", &n);

		bool all[2] = { 1,1 };

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);

			all[!(arr[i] % 2)] = false;
		}

		if (all[0] || (all[1] && !(n % 2)))
		{
			printf("NO\n");
		}

		else
		{
			printf("YES\n");
		}
	}

	return 0;
}