#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

int main()
{
	int n;
	vector<pair<int, int>> arr;
	pair<int, int> input;
	int input1, input2;
	int i, j;
	int sheet[5], pre[5];
	stack<int> circle;
	int cur, cand;
	int *state;

	state = new int[200001];

	scanf("%d", &n);

	arr.push_back(pair<int, int>(0, 0));

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &input1, &input2);

		arr.push_back(pair<int, int>(input1, input2));

		state[i + 1] = -1;
	}

	if (n == 3)
	{
		for (i = 1; i <= 3; i++)
		{
			printf("%d ", i);
		}

		return 0;
	}

	else if (n == 4)
	{
		for (i = 1; i <= 4; i++)
		{
			for (j = 1; j <= 4; j++)
			{
				sheet[j] = 0;
			}

			sheet[i] = 1;

			sheet[arr[i].first] = 1;
			sheet[arr[i].second] = 1;

			for (j = 1; j <= 4; j++)
			{
				if (!sheet[j])
				{
					pre[i] = j;

					break;
				}
			}
		}

		circle.push(1);

		for (i = 2; i <= 4; i++)
		{
			circle.push(pre[circle.top()]);
		}

		for (i = 1; i <= 4; i++)
		{
			cur = circle.top();

			circle.pop();

			printf("%d ", cur);
		}

		return 0;
	}

	else
	{
		for (i = 1; i <= n; i++)
		{
			if (state[i] == -1)
			{
				cur = i;

				cand = arr[i].first;

				if (arr[cur].second == arr[cand].first)
				{
					state[cur] = 0;
					state[cand] = 0;

					continue;
				}

				else if (arr[cur].second == arr[cand].second)
				{
					state[cur] = 0;
					state[cand] = 1;

					continue;
				}

				cand = arr[i].second;

				if (arr[cur].first == arr[cand].first)
				{
					state[cur] = 1;
					state[cand] = 0;

					continue;
				}

				else if (arr[cur].first == arr[cand].second)
				{
					state[cur] = 1;
					state[cand] = 1;

					continue;
				}
			}
		}
	}

	printf("1");

	if (state[1] == 0)
	{
		cur = arr[1].first;
	}

	else
	{
		cur = arr[1].second;
	}

	for (i = 0; i < n - 1; i++)
	{
		printf(" %d", cur);

		if (state[cur] == 0)
		{
			cur = arr[cur].first;
		}

		else
		{
			cur = arr[cur].second;
		}
	}

	return 0;
}