#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		int leftmax = 0, rightmin = 9999999999;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int l, r;

			scanf("%d %d", &l, &r);

			if (l > leftmax)
			{
				leftmax = l;
			}
			
			if (r < rightmin)
			{
				rightmin = r;
			}
		}

		if (leftmax > rightmin)
		{
			printf("%d\n", leftmax - rightmin);
		}

		else
		{
			printf("0\n");
		}
	}

	return 0;
}