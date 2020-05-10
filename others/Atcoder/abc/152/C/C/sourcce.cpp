#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	int lmin, cnt = 1;

	scanf("%d", &lmin);

	for (int i = 1; i < n; i++)
	{
		int val;

		scanf("%d", &val);

		cnt += (val <= lmin);

		if (val < lmin)
		{
			lmin = val;
		}
	}

	printf("%d\n", cnt);

	return 0;
}