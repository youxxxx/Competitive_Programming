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

#define MOD 1000000007

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int input;
		scanf("%d", &input);
		int sol = input;
		int cnt = 0;

		for (int i = 1; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			if (input)
			{
				cnt++;
			}

			else
			{
				sol += cnt / 3;

				cnt = 0;
			}
		}

		sol += cnt / 3;

		printf("%d\n", sol);
	}

	return 0;
}