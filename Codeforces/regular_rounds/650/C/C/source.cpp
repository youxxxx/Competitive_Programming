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
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, k;
		char input[200001];
		string str;

		scanf("%d %d", &n, &k);

		scanf("%s", input);
		str = input;

		vector<int> arr;

		for (int i = 0; i < n; i++)
		{
			if (str[i] == '1')
			{
				arr.push_back(i);
			}
		}

		if (arr.empty())
		{
			int sol = 1;

			if ((n + k) / (k + 1) > sol)
			{
				sol = (n + k) / (k + 1);
			}

			printf("%d\n", sol);

			continue;
		}

		int sol = 0;

		sol += arr[0] / (k + 1);

		for (int i = 1; i < arr.size(); i++)
		{
			int add = (arr[i] - arr[i - 1] - (k + 1)) / (k + 1);

			if (add > 0)
			{
				sol += add;
			}
		}

		sol += (n - 1 - arr.back()) / (k + 1);

		printf("%d\n", sol);
	}

	return 0;
}