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
	int n, s;

	scanf("%d %d", &n, &s);

	if (s < n * 2)
	{
		printf("NO\n");
	}

	else
	{
		printf("YES\n");

		for (int i = 0; i < n - 1; i++)
		{
			printf("1 ");
		}

		printf("%d\n", s - n + 1);

		printf("%d\n", n);
	}

	return 0;
}