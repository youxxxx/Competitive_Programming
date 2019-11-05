#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	bool visited[400001] = { 0, };
	vector<int> arr;
	int n;
	int i;
	int input;
	int lmin = 0;
	int cur = 0;

	scanf("%d", &n);

	arr.push_back(0);

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d", &input);

		cur += input;

		if (cur < lmin)
		{
			lmin = cur;
		}

		arr.push_back(cur);
	}

	for (i = 0; i < n; i++)
	{
		cur = arr[i] - lmin;

		if (cur >= n || visited[cur])
		{
			printf("-1\n");

			return 0;
		}

		visited[cur] = true;

		arr[i] -= lmin - 1;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}