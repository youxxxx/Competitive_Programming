#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, i;
	int sum = 0;
	int max = 0;
	int input;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		sum += input;

		if (input > max)
		{
			max = input;
		}
	}

	printf("%d\n", sum - max / 2);

	return 0;
}