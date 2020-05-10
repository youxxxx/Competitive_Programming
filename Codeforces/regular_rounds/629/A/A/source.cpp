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
		int a, b;

		scanf("%d %d", &a, &b);

		int sol;

		sol = (b - a%b) % b;

		printf("%d\n", sol);
	}

	return 0;
}