#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	long long n, k;
	long long pw, res;
	long long r, q;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld %lld", &n, &k);

		pw = 0;

		while (n != 0)
		{
			while (!(n%k))
			{
				n /= k;

				pw++;
			}

			pw += n%k;
			n -= n%k;
		}

		printf("%lld\n", pw);
	}

	return 0;
}