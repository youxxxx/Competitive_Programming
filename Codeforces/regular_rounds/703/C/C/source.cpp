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

	int n;

	scanf("%d", &n);

	int l = 1, r = n;
	printf("? %d %d\n", l, r);
	fflush(stdout);

	int prev;

	scanf("%d", &prev);

	while (r - l > 2)
	{
		int point = l + (int)((double)(r - l)*(sqrt(5.0) - 1.0) / 2.0);
		int mid;

		if (prev <= point)
		{
			/*
			if (mid - l < 3)
			{
				r = mid;

				break;
			}
			*/
			mid = point;

			printf("? %d %d\n", l, mid);
		}

		else
		{
			/*
			if (r - (mid + 1) < 3)
			{
				l = mid + 1;

				break;
			}
			*/
			mid = r - (int)((double)(r - l)*(sqrt(5.0) - 1.0) / 2.0);

			printf("? %d %d\n", mid + 1, r);
		}

		fflush(stdout);

		int cur;
		scanf("%d", &cur);

		if (cur == prev)
		{
			if (prev <= mid)
			{
				r = mid;
			}

			else
			{
				l = mid + 1;
			}
		}

		else
		{
			if (prev <= mid)
			{
				l = mid + 1;
			}

			else
			{
				r = mid;
			}

			printf("? %d %d\n", l, r);
			fflush(stdout);

			scanf("%d", &cur);
		}

		prev = cur;
	}

	int sol;

	if (r - l == 2)
	{
		if (prev == l + 1)
		{
			printf("? %d %d\n", l, l + 1);
			fflush(stdout);

			int input;

			scanf("%d", &input);

			if (input == prev)
			{
				sol = l;
			}

			else
			{
				sol = r;
			}
		}

		else
		{
			if (prev == l)
			{
				printf("? %d %d\n", l + 1, r);
				fflush(stdout);

				int input;

				scanf("%d", &input);

				sol = l + 1 + r - input;
			}

			else
			{
				printf("? %d %d\n", l, l + 1);
				fflush(stdout);

				int input;

				scanf("%d", &input);

				sol = l + l + 1 - input;
			}
		}
	}

	else if (r - l == 1)
	{
		printf("? %d %d\n", l, r);
		fflush(stdout);

		int input;

		scanf("%d", &input);

		sol = l + r - input;
	}

	else
	{
		sol = l;
	}

	printf("! %d\n", sol);
	fflush(stdout);

	return 0;
}