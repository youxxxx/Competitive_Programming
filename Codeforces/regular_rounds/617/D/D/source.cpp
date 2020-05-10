#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int main()
{
	int n;
	long long a, b, k;
	multiset<long long> list;

	scanf("%d", &n);
	scanf("%lld %lld %lld", &a, &b, &k);

	long long sol = 0;

	for (int i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		if (input <= a)
		{
			sol++;

			continue;
		}

		input %= (a + b);

		if (input == 0)
		{
			input = a + b;
		}

		if (input <= a)
		{
			sol++;
		}

		else
		{
			list.insert((input - 1) / a);
		}
	}

	long long left;

	left = k;

	for (set<long long>::iterator it = list.begin(); it != list.end(); it++)
	{
		if (*it > left)
		{
			break;
		}

		left -= *it;

		sol++;
	}

	printf("%lld\n", sol);

	return 0;
}