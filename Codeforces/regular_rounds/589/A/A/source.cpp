#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int l, r;
	int i, j;
	int cnt[10];
	int temp;
	bool same;

	scanf("%d %d", &l, &r);

	for (i = l; i <= r; i++)
	{
		temp = i;

		for (j = 0; j < 10; j++)
		{
			cnt[j] = 0;
		}

		same = false;

		while (temp)
		{
			if (cnt[temp % 10]++)
			{
				same = true;

				break;
			}

			temp /= 10;
		}

		if (!same)
		{
			printf("%d\n", i);

			return 0;
		}
	}

	printf("-1\n");

	return 0;
}