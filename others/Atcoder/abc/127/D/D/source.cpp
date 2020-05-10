#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main()
{
	long long n, m;
	long long input, num;
	map<long long, long long> val;
	map<long long, long long>::iterator it, ret;
	long long sum = 0;
	long long i, add, cnt = 0;

	scanf("%lld %lld", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		it = val.find(input);

		if (it == val.end())
		{
			val[input] = 1;
		}

		else
		{
			it->second++;
		}
	}

	for (i = 0; i < m; i++)
	{
		scanf("%lld %lld", &num, &input);

		it = val.find(input);

		if (it == val.end())
		{
			val[input] = num;
		}

		else
		{
			it->second += num;
		}
	}

	it = val.end();

	while (it--!=val.begin())
	{
		add = n - cnt < it->second ? n - cnt : it->second;

		sum += add*it->first;

		cnt += add;

		if (cnt == n)
		{
			break;
		}
	}

	printf("%lld\n", sum);

	return 0;
}