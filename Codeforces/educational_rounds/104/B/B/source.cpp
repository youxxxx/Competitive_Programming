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
		int n, m;

		scanf("%d %d", &n, &m);

		if (!(n % 2))
		{
			printf("%d\n", m%n + !(m%n)*n);

			continue;
		}

		if (m < (n + 1) / 2)
		{
			printf("%d\n", m);

			continue;
		}

		m += (m - 1) / ((n - 1) / 2);

		printf("%d\n", m%n + !(m%n)*n);
	}

	return 0;
}