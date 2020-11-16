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

	long long val[31];
	long long cur = 1;
	val[1] = 1;

	for (int i = 2; i <= 30; i++)
	{
		cur = cur * 2 + 1;

		val[i] = val[i - 1] + (cur*(cur + 1) / 2);
	}

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n;

		scanf("%lld", &n);

		for (int i = 1; i <= 30; i++)
		{
			if (i == 30 || val[i + 1] > n)
			{
				printf("%d\n", i);

				break;
			}
		}
	}

	return 0;
}