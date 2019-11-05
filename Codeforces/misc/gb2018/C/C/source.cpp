#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	long long n;
	long long sum;
	long long i;
	long long q;
	long long bound;
	vector<long long> divl, divu;

	scanf("%I64d", &n);

	bound = (long long)sqrt((double)n);

	for (i = 1; i <= bound; i++)
	{
		if (!(n%i))
		{
			divl.insert(divl.begin(), i);

			if (n / i != i)
			{
				divu.push_back(n / i);
			}
		}
	}

	for (i = 0; i < divu.size(); i++)
	{
		q = n / divu[i];

		printf("%I64d ", (q * (q + 1) / 2 * divu[i]) - (divu[i] - 1)*q);
	}

	for (i = 0; i < divl.size(); i++)
	{
		q = n / divl[i];

		printf("%I64d ", (q * (q + 1) / 2 * divl[i]) - (divl[i] - 1)*q);
	}

	return 0;
}

