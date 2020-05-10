#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;

	scanf("%d", &n);

	map<long long, long long> list;

	long long arr[200001];

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	long long acc = 0, sol = 0;
	long long val = 0;
	long long prev = -1;

	if (arr[0] != 0)
	{
		acc++;
		sol++;

		list[0] = 0;
	}

	else
	{
		prev = 0;
	}

	val = arr[0];

	for (int i = 1; i < n; i++)
	{
		map<long long, long long>::iterator ret;

		if (arr[i] == 0)
		{
			acc = 0;
			prev = i;

			continue;
		}

		ret = list.find(-arr[i] - val);

		if (ret != list.end() && ret->second > prev)
		{
			acc = i - ret->second - 1;
			prev = ret->second;
		}

		val += arr[i];
		sol += acc + 1;
		list[arr[i] - val] = i;
		acc++;
	}

	printf("%lld\n", sol);

	return 0;
}