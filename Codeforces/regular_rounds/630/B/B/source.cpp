#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	vector<int> prime = { 2,3,5,7,11,13,17,19,23,29,31 };

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		int color[1001];
		bool taken[11] = { 0, };

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			for (int j = 0; j < prime.size(); j++)
			{
				if (!(input%prime[j]))
				{
					color[i] = j;
					taken[j] = true;

					break;
				}
			}
		}

		int cnt = 0;
		int idx[11];

		for (int i = 0; i < 11; i++)
		{
			if (taken[i])
			{
				idx[i] = ++cnt;
			}
		}
		
		printf("%d\n", cnt);

		for (int i = 0; i < n; i++)
		{
			printf("%d ", idx[color[i]]);
		}

		printf("\n");
	}

	return 0;
}