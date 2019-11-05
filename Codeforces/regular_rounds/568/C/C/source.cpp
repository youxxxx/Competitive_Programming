#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;


int main()
{
	int n;
	long long m;
	int i;
	vector<long long> arr;
	vector<long long>::iterator ret;
	long long j;
	long long num[101] = { 0, };
	long long input;
	long long tot = 0, sub, val, q;
	int cnt = 0;

	scanf("%d %lld", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		sub = 0;
		cnt = 0;

		if (tot > m - input)
		{
			for (j = 100; j >= 1; j--)
			{
				val = num[j] * j;

				if (tot - sub - val <= m - input)
				{
					q = ((tot - sub) - (m - input) + j - 1) / j;

					cnt += q;

					break;
				}

				else
				{
					sub += num[j] * j;
					cnt += num[j];
				}
			}
		}

		printf("%d ", cnt);

		num[input]++;

		tot += input;
	}
	
	return 0;
}