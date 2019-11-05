#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	int n;
	vector<int> arr;
	int loc[100001][2];
	bool visited[100001] = { 0 };
	int input;
	int i;
	long long sol = 0;
	long long cand1, cand2;

	scanf("%d", &n);

	for (i = 0; i < n * 2; i++)
	{
		scanf("%d", &input);

		if (!visited[input])
		{
			loc[input][0] = i;

			visited[input] = true;
		}

		else
		{
			loc[input][1] = i;
		}
	}

	loc[0][0] = loc[0][1] = 0;

	for (i = 1; i <= n; i++)
	{
		cand1 = abs(loc[i - 1][0] - loc[i][0]) + abs(loc[i - 1][1] - loc[i][1]);
		cand2 = abs(loc[i - 1][0] - loc[i][1]) + abs(loc[i - 1][1] - loc[i][0]);

		sol += cand1 < cand2 ? cand1 : cand2;
	}

	printf("%I64d\n", sol);

	return 0;
}