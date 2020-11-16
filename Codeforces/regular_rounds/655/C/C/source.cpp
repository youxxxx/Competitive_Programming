#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int arr[200001];

		int n;

		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}

		bool cur = true;

		int sol = 0;

		for (int i = 1; i <= n; i++)
		{
			bool next = false;

			if (arr[i] == i)
			{
				next = true;
			}

			if (cur != next)
			{
				sol++;

				cur = next;
			}
		}

		if (sol > 2)
		{
			sol = 2;
		}

		else if (sol == 2)
		{
			sol = 1;
		}

		printf("%d\n", sol);
	}

	return 0;
}