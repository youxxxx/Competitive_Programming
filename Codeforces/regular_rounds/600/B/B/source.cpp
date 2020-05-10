#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	int present[1000001] = { 0, }, last[1000001];
	vector<int> sol, arr;
	int prev = -1;
	int n;
	int cnt = 0;
	int flag;

	scanf("%d", &n);

	memset(last, -1, sizeof(last));

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		flag = input / abs(input);

		input = abs(input);

		if (!present[input])
		{
			if (flag == -1)
			{
				printf("-1\n");

				return 0;
			}

			cnt++;
		}

		else
		{
			if (flag == 1)
			{
				printf("-1\n");

				return 0;
			}

			cnt--;
		}

		if (last[input] > prev && !present[input])
		{
			printf("-1\n");

			return 0;
		}

		if (!present[input])
		{
			last[input] = i;
		}

		present[input] = !present[input];

		if (cnt == 0)
		{
			sol.push_back(i - prev);

			prev = i;
		}
	}

	if (cnt != 0)
	{
		printf("-1\n");

		return 0;
	}

	printf("%d\n", sol.size());

	for (int i = 0; i < sol.size(); i++)
	{
		printf("%d ", sol[i]);
	}

	return 0;
}