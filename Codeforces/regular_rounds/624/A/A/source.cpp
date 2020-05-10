#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		if (a == b)
		{
			printf("0\n");
		}

		else if (a > b && !((a - b) % 2) || a < b && (b - a) % 2)
		{
			printf("1\n");
		}

		else
		{
			printf("2\n");
		}
	}

	return 0;
}