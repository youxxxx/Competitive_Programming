#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, l, a;
	int start, len, pre = 0;
	int i;
	int cnt = 0;

	scanf("%d %d %d", &n, &l, &a);

	if (n > 0)
	{
		scanf("%d %d", &start, &len);

		pre = start + len;

		cnt += start / a;
	}

	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &start, &len);

		cnt += (start - pre) / a;

		pre = start + len;
	}

	printf("%d", cnt + (l - pre) / a);

	return 0;
}