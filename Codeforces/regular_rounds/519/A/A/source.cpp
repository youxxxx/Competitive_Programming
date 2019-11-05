#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n;
	vector<int> arr;
	int input;
	int i;
	int max = 0;
	int sum = 0;
	int sol;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);

		sum += input;

		if (input > max)
		{
			max = input;
		}
	}

	sol = (2 * sum + n - 1) / n;

	if (sol*n == sum * 2)
	{
		sol++;
	}

	if (max > sol)
	{
		sol = max;
	}

	printf("%d", sol);

	return 0;
}