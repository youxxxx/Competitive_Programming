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
	long long x;
	long long cur = 100;

	scanf("%lld", &x);

	int cnt = 0;

	while (cur < x)
	{
		cur += cur / 100;

		cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}