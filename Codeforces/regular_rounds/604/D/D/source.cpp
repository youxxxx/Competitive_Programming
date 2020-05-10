#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n = 0;
	int num[4] = { 0, };

	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &num[i]);

		n += num[i];
	}

	for (int j = 0; j < 4; j++)
	{
		vector<int> sol;
		int temp[4];

		for (int i = 0; i < 4; i++)
		{
			temp[i] = num[i];
		}

		int cur;

		cur = j;

		for (int i = 0; i < n; i++)
		{
			if (temp[cur] == 0)
			{
				break;
			}

			sol.push_back(cur);
			temp[cur]--;

			if (cur == 0)
			{
				cur++;
			}

			else if (cur == 3)
			{
				cur--;
			}

			else if (temp[cur - 1] != 0)
			{
				cur--;
			}

			else
			{
				cur++;
			}
		}

		if (sol.size() == n)
		{
			printf("YES\n");

			for (int i = 0; i < n; i++)
			{
				printf("%d ", sol[i]);
			}

			return 0;
		}
	}

	printf("NO\n");

	return 0;
}