#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		vector<int> arr;
		int n;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			arr.push_back(input);
		}

		sort(arr.begin(), arr.end());

		int lmin = arr[1] - arr[0];

		for (int i = 1; i < n - 1; i++)
		{
			if (arr[i + 1] - arr[i] < lmin)
			{
				lmin = arr[i + 1] - arr[i];
			}
		}

		printf("%d\n", lmin);
	}

	return 0;
}