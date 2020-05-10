#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	long long cases;

	scanf("%lld", &cases);

	for (long long tc = 0; tc < cases; tc++)
	{
		long long n, x;

		scanf("%lld %lld", &n, &x);

		char input[100001];

		scanf("%s", input);

		string str;

		str = input;

		map<long long, long long> list;

		long long sol = 0;

		list[0] = 1;

		long long acc = 0;

		for (long long i = 0; i < n; i++)
		{
			map<long long, long long>::iterator ret;

			if (str[i] == '0')
			{
				acc++;
			}

			else
			{
				acc--;
			}

			ret = list.find(acc);

			if (ret == list.end())
			{
				list[acc] = 1;
			}

			else
			{
				ret->second++;
			}
		}

		map<long long, long long>::iterator ret;
		ret = list.find(acc);
		ret->second--;

		if (acc == 0)
		{
			map<long long, long long>::iterator ret;

			ret = list.find(x);

			if (ret == list.end())
			{
				printf("0\n");
			}

			else
			{
				printf("-1\n");
			}

			continue;
		}

		for (map<long long, long long>::iterator it = list.begin(); it != list.end(); it++)
		{
			if (((x - it->first) == 0 || (x - it->first) / abs((x - it->first)) == acc / abs(acc)) && !(abs(it->first - x) % abs(acc)))
			{
				sol += it->second;
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}