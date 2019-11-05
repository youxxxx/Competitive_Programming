#include<cstdio>

using namespace std;

int main()
{
	int in[101] = { 0, };

	int n, r, input;
	int i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &r);

		for (j = 0; j < r; j++)
		{
			scanf("%d", &input);

			in[input]++;
		}
	}

	for (i = 1; i <= 100; i++)
	{
		if (in[i] == n)
		{
			printf("%d ", i);
		}
	}

	return 0;
}