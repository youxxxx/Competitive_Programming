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

		vector<string> arr;

		for (int i = 0; i < n; i++)
		{
			char input[201];

			scanf("%s", input);

			const string str = input;

			arr.push_back(str);
		}

		char val[10];

		val[0] = arr[0][1];
		val[1] = arr[1][0];
		val[2] = arr[0][2];
		val[3] = arr[1][1];
		val[4] = arr[2][0];

		pair<int, int> coord[5] = { { 1,2 },{ 2,1 },{ 1,3 },{ 2,2 },{ 3,1 } };

		vector<pair<int, int>> sol;

		if (val[2] == val[3] && val[3] == val[4])
		{
			for (int i = 0; i <= 1; i++)
			{
				if (val[i] == val[2])
				{
					sol.push_back(coord[i]);
				}
			}

			printf("%d\n", sol.size());

			for (int i = 0; i < sol.size(); i++)
			{
				printf("%d %d\n", sol[i].first, sol[i].second);
			}

			continue;
		}

		if (val[0] == val[1])
		{
			for (int i = 2; i <= 4; i++)
			{
				if (val[i] == val[0])
				{
					sol.push_back(coord[i]);
				}
			}

			printf("%d\n", sol.size());

			for (int i = 0; i < sol.size(); i++)
			{
				printf("%d %d\n", sol[i].first, sol[i].second);
			}

			continue;
		}

		int cnt[2] = { 0, };

		for (int i = 2; i <= 4; i++)
		{
			cnt[val[i] - '0']++;
		}

		if (cnt[0] == 1)
		{
			for (int i = 2; i <= 4; i++)
			{
				if (val[i] == '0')
				{
					sol.push_back(coord[i]);

					break;
				}
			}

			for (int i = 0; i <= 1; i++)
			{
				if (val[i] == '1')
				{
					sol.push_back(coord[i]);

					break;
				}
			}
		}

		else
		{
			for (int i = 2; i <= 4; i++)
			{
				if (val[i] == '1')
				{
					sol.push_back(coord[i]);

					break;
				}
			}

			for (int i = 0; i <= 1; i++)
			{
				if (val[i] == '0')
				{
					sol.push_back(coord[i]);

					break;
				}
			}
		}

		printf("%d\n", sol.size());

		for (int i = 0; i < sol.size(); i++)
		{
			printf("%d %d\n", sol[i].first, sol[i].second);
		}
	}

	return 0;
}