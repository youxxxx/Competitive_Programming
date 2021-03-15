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

		if (n == 3)
		{
			printf("2\n3 2\n3 2\n");

			continue;
		}

		vector <pair<int, int>> sol;

		int target = (int)(cbrt((double)n)) + 1;

		for (int i = 3; i < n; i++)
		{
			if (i == target)
			{
				continue;
			}

			sol.push_back({ i,n });
		}

		sol.push_back({ n,target });
		sol.push_back({ n,target });
		sol.push_back({ n,target });

		if (target != 2)
		{
			int temp = target;

			while (temp != 1)
			{
				sol.push_back({ target,2 });

				temp = temp / 2 + temp % 2;
			}
		}

		printf("%d\n", (int)sol.size());

		for (int i = 0; i < (int)sol.size(); i++)
		{
			printf("%d %d\n", sol[i].first, sol[i].second);
		}
	}

	return 0;
}