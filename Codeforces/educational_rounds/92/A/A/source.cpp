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
		int l, r;

		scanf("%d %d", &l, &r);

		if (r % 2)
		{
			r--;
		}

		if (r / 2 >= l)
		{
			printf("%d %d\n", r / 2, r);
		}

		else
		{
			printf("-1 -1\n");
		}
	}

	return 0;
}