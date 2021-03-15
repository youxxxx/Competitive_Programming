#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		if (n == 45)
		{
			printf("123456789\n");

			continue;
		}

		int lmax = -1;

		for (int i = 1; i < 512; i++)
		{
			int temp = i;

			int sum = 0;
			int num = 0;
			int cnt = 1;

			while (temp)
			{
				if (temp % 2)
				{
					sum += cnt;
					num = num * 10 + cnt;
				}

				temp /= 2;
				cnt++;
			}

			if (sum == n && (lmax == -1 || num < lmax))
			{
				lmax = num;
			}
		}

		printf("%d\n", lmax);
	}

	return 0;
}