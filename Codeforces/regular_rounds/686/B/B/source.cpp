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
		int n;

		scanf("%d", &n);

		int idx[200001];

		for (int i = 1; i <= n; i++)
		{
			idx[i] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			if (!idx[input])
			{
				idx[input] = i + 1;
			}

			else
			{
				idx[input] = -1;
			}
		}

		int sol = -1;

		for (int i = 1; i <= n; i++)
		{
			if (idx[i] > 0)
			{
				sol = idx[i];

				break;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}