#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	map<long long, long long> list;
	vector<long long> arr;

	for (int i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		arr.push_back(input);

		map<long long, long long>::iterator ret;

		ret = list.find(input);

		if (ret == list.end())
		{
			list[input] = 1;
		}

		else
		{
			ret->second++;
		}
	}

	long long tot = 0;

	for (map<long long, long long>::iterator it = list.begin(); it != list.end(); it++)
	{
		tot += it->second*(it->second - 1) / 2;
	}

	for (int i = 0; i < n; i++)
	{
		map<long long, long long>::iterator ret;

		ret = list.find(arr[i]);

		long long sol;

		sol = tot;

		if (ret->second > 1)
		{
			sol -= ret->second - 1;
		}

		printf("%lld\n", sol);
	}

	return 0;
}