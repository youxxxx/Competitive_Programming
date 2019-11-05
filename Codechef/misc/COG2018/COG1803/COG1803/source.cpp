#include<cstdio>

using namespace std;

int main()
{
	int t, z;
	int n;
	int i;
	int input;
	int cnt;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		cnt = 0;

		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			cnt += input;
		}

		if (cnt >= 0)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}