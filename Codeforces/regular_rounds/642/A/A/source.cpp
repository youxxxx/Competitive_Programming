#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		if (n == 1)
		{
			printf("0\n");
		}

		else if (n == 2)
		{
			printf("%d\n", m);
		}

		else
		{
			printf("%d\n", m * 2);
		}
	}

	return 0;
}