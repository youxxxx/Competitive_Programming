#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			sum += input;
		}

		if (sum >= m)
		{
			printf("%d\n", m);
		}

		else
		{
			printf("%d\n", sum);
		}
	}

	return 0;
}