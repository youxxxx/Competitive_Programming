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

		for (int i = 1; i < m - (n - m); i++)
		{
			printf("%d ", i);
		}

		for (int i = m; i >= m - (n - m); i--)
		{
			printf("%d ", i);
		}

		printf("\n");
	}

	return 0;
}