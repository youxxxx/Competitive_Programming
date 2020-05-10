#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long n;

	scanf("%lld", &n);

	if (n % 2)
	{
		printf("0\n");
	}

	else
	{
		long long temp;
		long long sol = 0;

		temp = n;

		while (temp)
		{
			sol += temp / 10;

			temp /= 5;
		}

		printf("%lld\n", sol);
	}

	return 0;
}
