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

#define MOD 100030001

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int sol[101];

		int cnt = 1;

		for (int i = 0; i < n; i += 2)
		{
			sol[i] = cnt++;
		}

		for (int i = n - (n % 2) - 1; i >= n % 2; i -= 2)
		{
			sol[i] = cnt++;
		}

		for (int i = 0; i < n; i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0;
}