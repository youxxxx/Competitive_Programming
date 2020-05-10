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
	//freopen("input.txt", "r", stdin);

	int n;

	scanf("%d", &n);

	while (n)
	{
		if (n % 10 == 7)
		{
			printf("Yes\n");

			return 0;
		}

		n /= 10;
	}

	printf("No\n");

	return 0;
}