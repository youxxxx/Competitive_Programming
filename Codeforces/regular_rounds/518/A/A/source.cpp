#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n, m, k, l;
	long long sol;
	long long q, mul;

	scanf("%I64d %I64d %I64d %I64d", &n, &m, &k, &l);

	if (m > n)
	{
		sol = -1;
	}
	
	else
	{
		q = (l + k + m - 1) / m;

		mul = q*m;

		if (mul > n)
		{
			sol = -1;
		}

		else
		{
			sol = q;
		}
	}


	printf("%I64d\n", sol);

	return 0;
}