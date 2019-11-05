#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n;
	int sum = 0, cur = 0;
	vector<pair<int, int>> arr;
	vector<int> sol;
	int input;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(pair<int, int>(input, i + 1));

		sum += input;
	}

	sort(arr.begin() + 1, arr.end());

	for (i = 1; i < n; i++)
	{
		if (2 * arr[i].first > arr[0].first)
		{
			break;
		}

		cur += arr[i].first;
		sol.push_back(arr[i].second);
	}

	cur += arr[0].first;

	if (cur > sum / 2)
	{
		sol.insert(sol.begin(), 1);

		printf("%d\n", sol.size());

		for (i = 0; i < sol.size(); i++)
		{
			printf("%d ", sol[i]);
		}
	}

	else
	{
		printf("0\n");
	}

	return 0;
}