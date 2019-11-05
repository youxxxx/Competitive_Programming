#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	int n;
	int i, j, input, res = 0,cnt = 1;
	int tom = 0;

	scanf("%d", &n);

	for (i = 0; i < 4; i++)
	{
		scanf("%d", &input);

		tom += input;
	}

	for (i = 0; i < n - 1; i++)
	{
		res = 0;

		for (j = 0; j < 4; j++)
		{
			scanf("%d", &input);

			res += input;
		}

		if (res > tom)
		{
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}