#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	vector<int> a;
	int input;
	int i;
	int sum = 0, max = 0;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		a.push_back(input);

		if (input > max)
		{
			max = input;
		}

		sum += input;
	}

	if (max*n - (sum + m) >= 0)
	{
		printf("%d ", max);
	}

	else
	{
		printf("%d ", max + ((sum + m) - max*n + n - 1) / n);
	}

	printf("%d", max + m);

	return 0;
}