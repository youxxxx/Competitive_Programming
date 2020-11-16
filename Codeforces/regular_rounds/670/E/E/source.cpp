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

	int state[100001];

	int base = 1;

	for (int i = 1; i <= n; i++)
	{
		state[i] = 1;
	}

	int i = 2;

	bool flag = false;
	int last = 2;

	while (i != n)

	{
		int cnt = 0;

		for (int j = i; j <= n; j += i)
		{
			cnt += state[j];
			state[j] = 0;
		}

		bool found = false;

		printf("B %d\n", i);
		fflush(stdout);

		int input;
		scanf("%d", &input);

		if (cnt != input)
		{
			found = true;
		}

		else
		{
			printf("B %d\n", i);
			fflush(stdout);

			scanf("%d", &input);

			if (input)
			{
				found = true;
			}
		}

		if(found)
		{
			if (!flag)
			{
				flag = true;
			}

			base = i;
		}

		else if (flag)
		{
			printf("C %d\n", last);

			return 0;
		}

		last = i;

		i += base;
	}

	return 0;
}