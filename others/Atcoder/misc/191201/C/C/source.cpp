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

	int q, r;

	q = n / 100;
	r = n % 100;

	for (int i = 0; i <= q; i++)
	{
		int nq, nr;

		nq = q - i;
		nr = r + 100 * i;

		if (r <= q * 5)
		{
			printf("1\n");

			return 0;
		}
	}

	printf("0\n");

	return 0;
}