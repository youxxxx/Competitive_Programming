#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	long long n,x,y,d;
	long long left = 9000000001, right = 9000000001;
	long long min;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%I64d %I64d %I64d %I64d", &n, &x, &y, &d);

		left = 9000000001;
		right = 9000000001;

		if (!(abs(x - y) % d))
		{
			printf("%I64d\n", abs(x - y) / d);
		}

		else
		{
			if (!((y - 1) % d))
			{
				left = (x - 1 + d - 1) / d + (y - 1) / d;
			}

			if (!((n - y) % d))
			{
				right = (n - x + d - 1) / d + (n - y) / d;
			}

			if (left == 9000000001 && right == 9000000001)
			{
				printf("-1\n");
			}

			else
			{
				min = right < left ? right : left;

				printf("%I64d\n", min);
			}
		}
	}


	return 0;
}