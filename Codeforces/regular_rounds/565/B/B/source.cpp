#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 1000000007;

using namespace std;

int main()
{
	int t, z;
	int cnt[3];
	int add;
	int n;
	int i;
	long long input;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		cnt[0] = cnt[1] = cnt[2] = 0;

		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			cnt[input % 3]++;
		}

		add = cnt[1] < cnt[2] ? cnt[1] : cnt[2];
		cnt[0] += add;
		cnt[1] -= add;
		cnt[2] -= add;

		cnt[0] += cnt[1] / 3 + cnt[2] / 3;

		printf("%d\n",cnt[0]);
	}

	return 0;
}