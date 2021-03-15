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
		int n, m;

		scanf("%d %d", &n, &m);

		if (n < m)
		{
			int temp = n;
			n = m;
			m = temp;
		}

		int sol;

		if (n <= m + 1)
		{
			sol = n + m;
		}

		else
		{
			sol = m * 2 + 1 + (n - (m + 1)) * 2;
		}

		printf("%d\n", sol);
	}

	return 0;
}