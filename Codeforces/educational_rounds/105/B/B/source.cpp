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

void io()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
}

int main()
{
	io();

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		int arr[5];

		scanf("%d", &n);
		
		for (int i = 0; i < 4; i++)
		{
			scanf("%d", &arr[i]);
		}

		bool found = false;

		for (int i = 0; i < 16; i++)
		{
			int corner[4];

			int temp = i;

			for (int j = 0; j < 4; j++)
			{
				corner[j] = temp % 2;

				temp /= 2;
			}

			bool valid = true;

			for (int j = 0; j < 4; j++)
			{
				const int left = arr[j] - (corner[j] + corner[(j + 1) % 4]);

				if (left < 0 || left > n - 2)
				{
					valid = false;

					break;
				}
			}

			if (valid)
			{
				found = true;

				break;
			}
		}

		if (found)
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