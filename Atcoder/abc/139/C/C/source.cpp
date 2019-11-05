#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int lmax = 0;
	int n;
	int len = -1, cur = -1;
	int i;
	int input;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (input > cur)
		{
			len = 0;
		}

		else
		{
			len++;
		}

		cur = input;

		if (len > lmax)
		{
			lmax = len;
		}
	}

	printf("%d\n", lmax);

	return 0;
}