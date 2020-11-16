#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}

		int sol = a * 2 > b ? a * 2 : b;

		printf("%d\n", sol*sol);
	}

	return 0;
}