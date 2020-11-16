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

		scanf("%d %d", &n, &k);

		vector<int> list[1001];

		for (int i = 0; i < k; i++)
		{
			int num;

			scanf("%d", &num);

			for (int j = 0; j < num; j++)
			{
				int input;

				scanf("%d", &input);

				list[i].push_back(input);
			}
		}

		if (k == 1)
		{
			bool check[1001] = { 0, };

			for (int i = 0; i < list[0].size(); i++)
			{
				check[list[0][i]] = true;
			}

			printf("? %d", n - list[0].size());

			for (int i = 1; i <= n; i++)
			{
				if (!check[i])
				{
					printf(" %d", i);
				}
			}

			printf("\n");
			fflush(stdout);

			int sol;

			scanf("%d", &sol);

			printf("! %d\n", sol);
			fflush(stdout);

			char input[20];
			string str;

			scanf("%s", input);
			str = input;

			if (str == "Incorrect")
			{
				return 0;
			}

			continue;
		}

		printf("? %d", n);

		for (int i = 1; i <= n; i++)
		{
			printf(" %d", i);
		}

		printf("\n");
		fflush(stdout);

		int lmax;

		scanf("%d", &lmax);

		int left = 0, right = k;

		while (right - left > 1)
		{
			int next = (left + right) / 2;

			vector<int> temp;

			for (int i = left; i < next; i++)
			{
				for (int j = 0; j < list[i].size(); j++)
				{
					temp.push_back(list[i][j]);
				}
			}

			printf("? %d", temp.size());

			for (int i = 0; i < temp.size(); i++)
			{
				printf(" %d", temp[i]);
			}

			printf("\n");
			fflush(stdout);

			int input;

			scanf("%d", &input);

			if (input == lmax)
			{
				right = next;
			}

			else
			{
				left = next;
			}
		}

		bool check[1001] = { 0, };

		for (int i = 0; i < list[left].size(); i++)
		{
			check[list[left][i]] = true;
		}

		printf("? %d", n - list[left].size());
		fflush(stdin);

		for (int i = 1; i <= n; i++)
		{
			if (!check[i])
			{
				printf(" %d", i);
			}
		}

		printf("\n");
		fflush(stdout);

		int second;

		scanf("%d", &second);

		printf("!");

		for (int i = 0; i < k; i++)
		{
			if (i == left)
			{
				printf(" %d", second);
			}

			else
			{
				printf(" %d", lmax);
			}
		}

		printf("\n");
		fflush(stdout);

		char input[20];
		string str;

		scanf("%s", input);
		str = input;

		if (str == "Incorrect")
		{
			return 0;
		}
	}

	return 0;
}