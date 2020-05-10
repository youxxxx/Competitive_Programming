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
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++)
	{
		printf("%d %d\n", i, n - i);
	}

	return 0;
}