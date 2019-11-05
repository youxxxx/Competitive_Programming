#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, k;
	long long cnt[101] = { 0, };
	long long input;
	long long sol = 0;
	int i;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		cnt[input%k]++;
	}

	for (i = 1; i <= k / 2 - !(k%2); i++)
	{
		sol += cnt[i] < cnt[k - i] ? cnt[i] : cnt[k - i];
	}

	sol += cnt[0] / 2;

	if (!(k % 2))
	{
		sol += cnt[k / 2] / 2;
	}

	printf("%I64d\n", sol * 2);

	return 0;
}